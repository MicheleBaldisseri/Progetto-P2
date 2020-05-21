#include "mainwindow.h"
#include "controller.h"

MainWindow::MainWindow(Controller* c, QWidget *parent) : QWidget(parent), controller(c) {
    mainLayout = new QVBoxLayout(this);
    itemLayout = new QHBoxLayout();
    menuLayout = new QVBoxLayout();
    listLayout = new QVBoxLayout();
    buttonListLayout = new QHBoxLayout();

    addMainItems();

    addButtons();
    addList();

    setWindowStyle();

    setLayout(mainLayout);

    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(showTime()));
    timer->start(1000);
}

void MainWindow::addEventList(string text, int color){
    QListWidget* list = static_cast<QListWidget*>(listLayout->itemAt(1)->widget());
    QListWidgetItem* item = new QListWidgetItem(QString::fromStdString(text),list);
    QColor c = QColor();
    switch(color){
    case 0://white
        c=QColor(255,255,255,20);
        break;
    case 1://red
        c=QColor(255,0,0,20);
        break;
    case 2://green
        c=QColor(0,255,0,20);
        break;
    case 3://yellow
        c=QColor(255,255,0,20);
        break;
    case 4://orange
        c=QColor(255,100,0,20);
        break;
    case 5://black
        c=QColor(0,0,0,20);
        break;
    case 6://blue
        c=QColor(0,0,255,20);
        break;
    case 7://purple
        c=QColor(255,0,255,20);
        break;
    case 8://grey
        c=QColor(105,105,105,20);
        break;
    }

    item->setBackgroundColor(c);
    list->addItem(item);
}

void MainWindow::updateList(){
    QDate selDate = static_cast<QCalendarWidget*>(itemLayout->itemAt(1)->widget())->selectedDate();
    clearList();
    controller->updateList(selDate); //da trasformare in segnale se necessario
}

void MainWindow::clearList(){
    QListWidget* list = static_cast<QListWidget*>(listLayout->itemAt(1)->widget());
    list->clear();
}

void MainWindow::showMessage(bool done, QString title, QString messagge)
{
    if(done)
        QMessageBox::information(this, title, messagge);
    else
        QMessageBox::warning(this, title, messagge);
}



void MainWindow::showTime(){
    QString s = QDateTime::currentDateTime().toString("dd MMMM yyyy hh:mm:ss");
    s[3] = s.at(3).toTitleCase();
    static_cast<QLabel*>(mainLayout->itemAt(0)->widget())->setText(s);

}

void MainWindow::inserisciEvento(int type)
{
    QDate selDate =  static_cast<QCalendarWidget*>(itemLayout->itemAt(1)->widget())->selectedDate();

    switch (type) {
    case 0:
        promW= new PromWindow(this, selDate);
        connect(promW,SIGNAL(eventoInserito(DatiEvento*)),controller,SLOT(dataFromWindow(DatiEvento*)));
        promW->show();
        break;
    case 1:
        appunW= new AppunWindow(this, selDate);
        connect(appunW,SIGNAL(eventoInserito(DatiEvento*)),controller,SLOT(dataFromWindow(DatiEvento*)));
        appunW->show();
        break;
    case 2:
        impW= new ImpWindow(this, selDate);
        connect(impW,SIGNAL(eventoInserito(DatiEvento*)),controller,SLOT(dataFromWindow(DatiEvento*)));
        impW->show();
        break;
    case 3:
        compW= new CompWindow(this,selDate);
        connect(compW,SIGNAL(eventoInserito(DatiEvento*)),controller,SLOT(dataFromWindow(DatiEvento*)));
        compW->show();
        break;
    default:
        break;
    }
}

void MainWindow::eliminaEvento(){
    QListWidget* list = static_cast<QListWidget*>(listLayout->itemAt(1)->widget());
    QList<QListWidgetItem*> selected = list->selectedItems();
    if(!(selected.isEmpty())){
        int pos = list->row(selected[0]);

        QMessageBox::StandardButton conferma;
        conferma = QMessageBox::question(this,"Conferma eliminazione", "Vuoi eliminare l'evento selezionato?", QMessageBox::Yes|QMessageBox::No);
        if (conferma == QMessageBox::Yes) {
            controller->eliminaEvento(pos); //da trasformare in segnale se necessario
        }
    }
}

void MainWindow::modificaEvento(){
    QListWidget* list = static_cast<QListWidget*>(listLayout->itemAt(1)->widget());
    QList<QListWidgetItem*> selected = list->selectedItems();
    if(!(selected.isEmpty())){
        int pos = list->row(selected[0]);
        controller->modificaEvento(pos); //da trasformare in segnale se necessario

    }
}


void MainWindow::addMainItems(){    //ogni widget puo essere spostato come campo privato, se deve essere usato da altri metodi

    QString s = QDateTime::currentDateTime().toString("dd MMMM yyyy hh:mm:ss");
    s[3] = s.at(3).toTitleCase();
    QLabel* date = new QLabel(s,this);
    date->setObjectName("date");
    date->setAlignment(Qt::AlignCenter);
    mainLayout->addWidget(date);

    QFrame *line = new QFrame();
    line->setFrameShape(QFrame::HLine);
    line->setObjectName("line");
    mainLayout->addWidget(line);

    mainLayout->addLayout(itemLayout);

    itemLayout->addLayout(menuLayout);

    QCalendarWidget* calendar = new QCalendarWidget(this);
    itemLayout->addWidget(calendar);
    calendar->setGridVisible(true);
    calendar->setMinimumWidth(380);
    calendar->setMaximumHeight(320);


    connect(calendar,SIGNAL(clicked(QDate)),controller,SLOT(updateList(QDate)));
    itemLayout->addLayout(listLayout);
}

void MainWindow::addList(){
    listLayout->addLayout(buttonListLayout);

    QPushButton* elimina = new QPushButton("Elimina",this);
    QPushButton* modifica = new QPushButton("Modifica",this);

    buttonListLayout->addWidget(elimina);
    buttonListLayout->addWidget(modifica);

    QListWidget *list = new QListWidget(this);
    listLayout->addWidget(list);

    connect(elimina,SIGNAL(clicked()),this,SLOT(eliminaEvento()));
    connect(modifica,SIGNAL(clicked()),this,SLOT(modificaEvento()));
}

void MainWindow::addButtons(){

    //QPushButton* inserisci = new QPushButton("Inserisci nuovo evento");
    QToolButton* inserisci = new QToolButton(this);
    inserisci->setPopupMode(QToolButton::InstantPopup);
    inserisci->setObjectName("inserisci");
    inserisci->setText("Inserisci nuovo evento   ");
    inserisci->setFixedWidth(180);


    QMenu* menu = new QMenu(inserisci);
    inserisci->setMenu(menu);
    menu->setFixedWidth(180);

    QAction* promemoria = new QAction("Promemoria",menu);
    QAction* appuntamento = new QAction("Appuntamento",menu);
    QAction* impegno = new QAction("Impegno",menu);
    QAction* compleanno = new QAction("Compleanno",menu);

    menu->addAction(promemoria);
    menu->addAction(appuntamento);
    menu->addAction(impegno);
    menu->addAction(compleanno);

    connect(promemoria, &QAction::triggered, this, [this]{ inserisciEvento(0);});
    connect(appuntamento, &QAction::triggered, this, [this]{ inserisciEvento(1);});
    connect(impegno, &QAction::triggered, this, [this]{ inserisciEvento(2);});
    connect(compleanno, &QAction::triggered, this, [this]{ inserisciEvento(3);});


    QPushButton* salva = new QPushButton("Salva eventi",this);
    QPushButton* esci = new QPushButton("Esci",this);

    connect(esci,SIGNAL(clicked()),this,SLOT(close()));
    connect(salva,SIGNAL(clicked()),controller,SLOT(exportEvents()));

    menuLayout->addSpacerItem(new QSpacerItem(180,20,QSizePolicy::Minimum,QSizePolicy::Expanding));
    menuLayout->addWidget(inserisci);
    menuLayout->addWidget(salva);
    menuLayout->addWidget(esci);
    menuLayout->addSpacerItem(new QSpacerItem(180,20,QSizePolicy::Minimum,QSizePolicy::Expanding));

    //menu->setFont(QFont("AdobeHeitiStd-Regular",30,QFont::Bold));

    menuLayout->setAlignment(inserisci,Qt::AlignTop);
    menuLayout->setAlignment(salva,Qt::AlignTop);
    menuLayout->setAlignment(esci,Qt::AlignTop);

}

void MainWindow::setWindowStyle(){
    setWindowTitle(tr("Agenda"));

    mainLayout->setContentsMargins(20,15,20,20);
    mainLayout->setSpacing(10);
    setGeometry(200,200,900,350);
    itemLayout->setSpacing(35);
    itemLayout->setContentsMargins(5,0,0,0);
    listLayout->setSpacing(10);

    QFile file(":/style.css");
    file.open(QFile::ReadOnly);
    QString styleSheet = QLatin1String(file.readAll());

    setStyleSheet(styleSheet);

}
