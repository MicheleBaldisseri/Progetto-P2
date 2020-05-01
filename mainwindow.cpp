#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QWidget(parent) {
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

void MainWindow::showTime()
{
   static_cast<QLabel*>(mainLayout->itemAt(0)->widget())->setText(QDateTime::currentDateTime().toString("dd/MM/yyyy hh:mm:ss"));
}

void MainWindow::addMainItems(){    //ogni widget puo essere spostato come campo privato, se deve essere usato da altri metodi

    QLabel* date = new QLabel(QDateTime::currentDateTime().toString("dd/MM/yyyy hh:mm:ss"));
    date->setObjectName("date");
    date->setAlignment(Qt::AlignCenter);
    mainLayout->addWidget(date);

    mainLayout->addLayout(itemLayout);
    itemLayout->addLayout(menuLayout);

    QCalendarWidget* calendar = new QCalendarWidget();
    itemLayout->addWidget(calendar);
    calendar->setGridVisible(true);
    calendar->setMinimumWidth(380);
    calendar->setMaximumHeight(320);

    itemLayout->addLayout(listLayout);
}

void MainWindow::addList(){
    listLayout->addLayout(buttonListLayout);

    QPushButton* elimina = new QPushButton("Elimina");
    QPushButton* modifica = new QPushButton("Modifica");

    buttonListLayout->addWidget(elimina);
    buttonListLayout->addWidget(modifica);

    QListView *list = new QListView();
    listLayout->addWidget(list);
}

void MainWindow::addButtons(){

    QPushButton* inserisci = new QPushButton("Inserisci nuovo evento",this);
    QPushButton* salva = new QPushButton("Salva eventi");
    QPushButton* colori = new QPushButton("Cambia colore eventi");

    menuLayout->addSpacerItem(new QSpacerItem(150,20,QSizePolicy::Minimum,QSizePolicy::Expanding));
    menuLayout->addWidget(inserisci);
    menuLayout->addWidget(salva);
    menuLayout->addWidget(colori);
    menuLayout->addSpacerItem(new QSpacerItem(150,20,QSizePolicy::Minimum,QSizePolicy::Expanding));

    //menu->setFont(QFont("AdobeHeitiStd-Regular",30,QFont::Bold));


    menuLayout->setAlignment(inserisci,Qt::AlignTop);
    menuLayout->setAlignment(salva,Qt::AlignTop);
    menuLayout->setAlignment(colori,Qt::AlignTop);

}

void MainWindow::setWindowStyle(){
    mainLayout->setContentsMargins(0,20,0,0);
    mainLayout->setSpacing(30);
    setGeometry(200,200,900,350);
    itemLayout->setSpacing(35);
    itemLayout->setContentsMargins(30,0,0,0);
    listLayout->setSpacing(10);

    QFile file(":/style.css");
    file.open(QFile::ReadOnly);
    QString styleSheet = QLatin1String(file.readAll());

    setStyleSheet(styleSheet);

}
