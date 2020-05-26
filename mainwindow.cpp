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

    QTimer *timer = new QTimer(this); //timer per mostrare data e ora in tempo reale
    connect(timer, SIGNAL(timeout()), this, SLOT(showTime()));
    timer->start(1000);
}

void MainWindow::addEventList(const string& text, const int& color){
    QListWidget* list = static_cast<QListWidget*>(listLayout->itemAt(1)->widget()); //ricava la lista della vista
    QListWidgetItem* item = new QListWidgetItem(QString::fromStdString(text),list); //crea l'item
    QColor c = QColor();
    switch(color){ //trasforma int in QColor
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

    item->setBackgroundColor(c); //setta il colore
    list->addItem(item); //aggiunge l'item
}

void MainWindow::updateList(){
    QDate selDate = static_cast<QCalendarWidget*>(itemLayout->itemAt(1)->widget())->selectedDate(); //ricava la data selezionata
    clearList(); //pulisce la lista
    controller->updateList(selDate); //passa la data al controller
}

void MainWindow::clearList(){
    QListWidget* list = static_cast<QListWidget*>(listLayout->itemAt(1)->widget()); //ricava la lsita
    list->clear();
}

void MainWindow::showMessage(const bool& done, QString title, QString messagge)
{
    if(done)
        QMessageBox::information(this, title, messagge);
    else
        QMessageBox::warning(this, title, messagge);
}

void MainWindow::initializeModifica(DatiEvento* e){
    switch (e->type) {//chiama la rispettiva finestra in base al tipo
    case 0:
        promW= new PromWindow(this, e->dataSelezionata,e);
        connect(promW,SIGNAL(eventoInserito(DatiEvento*,bool)),controller,SLOT(dataFromWindow(DatiEvento*,bool)));
        promW->exec();
        break;
    case 1:
        appunW= new AppunWindow(this, e->dataSelezionata,e);
        connect(appunW,SIGNAL(eventoInserito(DatiEvento*,bool)),controller,SLOT(dataFromWindow(DatiEvento*,bool)));
        appunW->exec();
        break;
    case 2:
        compW= new CompWindow(this, e->dataSelezionata, e);
        connect(compW,SIGNAL(eventoInserito(DatiEvento*,bool)),controller,SLOT(dataFromWindow(DatiEvento*,bool)));
        compW->exec();
        break;
    case 3:
        impW= new ImpWindow(this, e->dataSelezionata, e);
        connect(impW,SIGNAL(eventoInserito(DatiEvento*,bool)),controller,SLOT(dataFromWindow(DatiEvento*,bool)));
        impW->exec();
        break;
    default:
        break;
    }
}

int MainWindow::getPos()
{
    QListWidget* list = static_cast<QListWidget*>(listLayout->itemAt(1)->widget()); //ricava la lista
    QList<QListWidgetItem*> selected = list->selectedItems(); //prende l'item selezionato
    return list->row(selected[0]); //ritorna la posizione
}



void MainWindow::showTime(){
    QString s = QDateTime::currentDateTime().toString("dd MMMM yyyy hh:mm:ss"); //trasforma QDateTime in QString per la label
    s[3] = s.at(3).toTitleCase(); //nome del mese con la lettera iniziale in maiuscolo, Qt lo traduce tutto in minuscolo
    static_cast<QLabel*>(mainLayout->itemAt(0)->widget())->setText(s); //setta la stringa

}

void MainWindow::inserisciEvento(int type)
{
    QDate selDate =  static_cast<QCalendarWidget*>(itemLayout->itemAt(1)->widget())->selectedDate(); //ricava la data selezionata

    switch (type) { //chiama la rispettiva finestra in base al tasto cliccato
    case 0:
        promW= new PromWindow(this, selDate);
        connect(promW,SIGNAL(eventoInserito(DatiEvento*,bool)),controller,SLOT(dataFromWindow(DatiEvento*,bool)));
        promW->exec();
        break;
    case 1:
        appunW= new AppunWindow(this, selDate);
        connect(appunW,SIGNAL(eventoInserito(DatiEvento*,bool)),controller,SLOT(dataFromWindow(DatiEvento*,bool)));
        appunW->exec();
        break;
    case 2:
        impW= new ImpWindow(this, selDate);
        connect(impW,SIGNAL(eventoInserito(DatiEvento*,bool)),controller,SLOT(dataFromWindow(DatiEvento*,bool)));
        impW->exec();
        break;
    case 3:
        compW= new CompWindow(this, selDate);
        connect(compW,SIGNAL(eventoInserito(DatiEvento*,bool)),controller,SLOT(dataFromWindow(DatiEvento*,bool)));
        compW->exec();
        break;
    default:
        break;
    }
}

void MainWindow::eliminaEvento(){
    QListWidget* list = static_cast<QListWidget*>(listLayout->itemAt(1)->widget());
    QList<QListWidgetItem*> selected = list->selectedItems();
    if(!(selected.isEmpty())){ //controlla che esiste un elemento selezionato
        int pos = list->row(selected[0]);

        QMessageBox::StandardButton conferma;
        conferma = QMessageBox::question(this,"Conferma eliminazione", "Vuoi eliminare l'evento selezionato?", QMessageBox::Yes|QMessageBox::No); //finestra di conferma
        if (conferma == QMessageBox::Yes) {
            controller->eliminaEvento(pos); //richiama il controller per eliminare l'evento
        }
    }
}

void MainWindow::modificaEvento(){
    QListWidget* list = static_cast<QListWidget*>(listLayout->itemAt(1)->widget());
    QList<QListWidgetItem*> selected = list->selectedItems();
    if(!(selected.isEmpty())){ //controlla che esiste un elemento selezionato
        int pos = list->row(selected[0]);
        controller->modificaEvento(pos); //richiama il controller per inizializzare la modifica dell'evento

    }
}


void MainWindow::addMainItems(){

    QString s = QDateTime::currentDateTime().toString("dd MMMM yyyy hh:mm:ss"); //data e ora
    s[3] = s.at(3).toTitleCase();
    QLabel* date = new QLabel(s,this);
    date->setObjectName("date");
    date->setAlignment(Qt::AlignCenter);
    mainLayout->addWidget(date);

    QFrame *line = new QFrame(); //linea spaziatrice
    line->setFrameShape(QFrame::HLine);
    line->setObjectName("line");
    mainLayout->addWidget(line);

    mainLayout->addLayout(itemLayout);

    itemLayout->addLayout(menuLayout); //layout tasti a sinistra

    QCalendarWidget* calendar = new QCalendarWidget(this); //calendario
    itemLayout->addWidget(calendar);
    calendar->setGridVisible(true);
    calendar->setMinimumWidth(380);
    calendar->setMaximumHeight(320);


    connect(calendar,SIGNAL(clicked(QDate)),controller,SLOT(updateList(QDate))); //connetto la selezione di una data all'aggiornamento della lista
    itemLayout->addLayout(listLayout); //layout lista
}

void MainWindow::addList(){
    listLayout->addLayout(buttonListLayout);


    QPushButton* elimina = new QPushButton(QIcon(":icone/delete.svg"),"Elimina",this); //tasto elimina
    QPushButton* modifica = new QPushButton(QIcon(":icone/edit.svg"),"Modifica",this); //tasto modifica

    buttonListLayout->addWidget(elimina);
    buttonListLayout->addWidget(modifica);

    QListWidget *list = new QListWidget(this); //lista
    listLayout->addWidget(list);

    connect(elimina,SIGNAL(clicked()),this,SLOT(eliminaEvento())); //connetto elimina
    connect(modifica,SIGNAL(clicked()),this,SLOT(modificaEvento())); //connetto modifica
}

void MainWindow::addButtons(){

    QToolButton* inserisci = new QToolButton(this); //toolbutton inserisci nuovo evento
    inserisci->setPopupMode(QToolButton::InstantPopup);
    inserisci->setObjectName("inserisci");
    inserisci->setText("Inserisci nuovo evento   ");
    inserisci->setFixedWidth(180);


    QMenu* menu = new QMenu(inserisci); //menu a tendina di inserisci evento
    inserisci->setMenu(menu);
    menu->setFixedWidth(180);

    QAction* promemoria = new QAction("Promemoria",menu); //tasti del menu a tendina
    QAction* appuntamento = new QAction("Appuntamento",menu);
    QAction* impegno = new QAction("Impegno",menu);
    QAction* compleanno = new QAction("Compleanno",menu);

    menu->addAction(promemoria);
    menu->addAction(appuntamento);
    menu->addAction(impegno);
    menu->addAction(compleanno);

    connect(promemoria, &QAction::triggered, this, [this]{ inserisciEvento(0);}); //connect (con formato diverso, per passare il tipo di tasto cliccato) all'inserimento
    connect(appuntamento, &QAction::triggered, this, [this]{ inserisciEvento(1);});
    connect(impegno, &QAction::triggered, this, [this]{ inserisciEvento(2);});
    connect(compleanno, &QAction::triggered, this, [this]{ inserisciEvento(3);});

    QPushButton* salva = new QPushButton(QIcon(":icone/save.svg"),"Salva eventi",this); //tasto salva eventi
    QPushButton* esci = new QPushButton(QIcon(":icone/exit.svg"),"Esci",this); //tasto per uscire

    connect(esci,SIGNAL(clicked()),this,SLOT(close())); //connect alla chiusura
    connect(salva,SIGNAL(clicked()),controller,SLOT(exportEvents())); //connect all'export

    menuLayout->addSpacerItem(new QSpacerItem(180,20,QSizePolicy::Minimum,QSizePolicy::Expanding)); //spacerItem per migliore spaziatura
    menuLayout->addWidget(inserisci);
    menuLayout->addWidget(salva);
    menuLayout->addWidget(esci);
    menuLayout->addSpacerItem(new QSpacerItem(180,20,QSizePolicy::Minimum,QSizePolicy::Expanding)); //spacerItem per migliore spaziatura

    menuLayout->setAlignment(inserisci,Qt::AlignTop);
    menuLayout->setAlignment(salva,Qt::AlignTop);
    menuLayout->setAlignment(esci,Qt::AlignTop);

}

void MainWindow::setWindowStyle(){
    setWindowTitle(tr("Agenda")); //titolo finestra

    mainLayout->setContentsMargins(20,15,20,20); //vari spacing e dimensioni
    mainLayout->setSpacing(10);
    setGeometry(200,200,900,350);
    itemLayout->setSpacing(35);
    itemLayout->setContentsMargins(5,0,0,0);
    listLayout->setSpacing(10);

    QFile file(":/style.css"); //file css
    file.open(QFile::ReadOnly);
    QString styleSheet = QLatin1String(file.readAll());

    setStyleSheet(styleSheet);

}
