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
}

void MainWindow::addMainItems(){    //ogni widget puo essere spostato come campo privato, se deve essere usato da altri metodi

    QDate currentDate = QDate::currentDate();
    QLabel* date = new QLabel(currentDate.toString("dd-MM-yyyy"));
    mainLayout->addWidget(date);

    mainLayout->addLayout(itemLayout);
    itemLayout->addLayout(menuLayout);

    QFrame *line1 = new QFrame();
    line1->setFrameShape(QFrame::VLine);
    itemLayout->addWidget(line1);

    QCalendarWidget* calendar = new QCalendarWidget();
    itemLayout->addWidget(calendar);

    QFrame *line2 = new QFrame();
    line2->setFrameShape(QFrame::VLine);
    itemLayout->addWidget(line2);

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
    QLabel *menu = new QLabel("Menù");
    QPushButton* inserisci = new QPushButton("Inserisci nuovo evento",this);
    QPushButton* salva = new QPushButton("Salva eventi");
    QPushButton* colori = new QPushButton("Cambia colore eventi");

    menuLayout->addWidget(menu);
    menuLayout->addSpacerItem(new QSpacerItem(150,20,QSizePolicy::Minimum,QSizePolicy::Minimum));
    menuLayout->addWidget(inserisci);
    menuLayout->addWidget(salva);
    menuLayout->addWidget(colori);
    menuLayout->addSpacerItem(new QSpacerItem(150,20,QSizePolicy::Minimum,QSizePolicy::Expanding));

    menu->setFont(QFont("AdobeHeitiStd-Regular",30,QFont::Bold));

    menuLayout->setAlignment(menu,Qt::AlignCenter);
    menuLayout->setAlignment(inserisci,Qt::AlignTop);
    menuLayout->setAlignment(salva,Qt::AlignTop);
    menuLayout->setAlignment(colori,Qt::AlignTop);
    menuLayout->setContentsMargins(0,20,0,0);

}

void MainWindow::setWindowStyle(){

}
