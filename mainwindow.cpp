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

void MainWindow::addMainItems(){

    QDate currentDate = QDate::currentDate();
    QLabel* date = new QLabel(currentDate.toString("dd-MM-yyyy"));
    mainLayout->addWidget(date);

    mainLayout->addLayout(itemLayout);
    itemLayout->addLayout(menuLayout);

    QFrame *line1 = new QFrame();
    line1->setFrameShape(QFrame::VLine);
    itemLayout->addWidget(line1);

    QCalendarWidget* calendar = new QCalendarWidget(); //si può spostare come campo privato se necessario
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
    QPushButton* inserisci = new QPushButton("Inserisci nuovo evento");
    QPushButton* salva = new QPushButton("Salva eventi");
    QPushButton* colori = new QPushButton("Cambia colore eventi");

    menuLayout->addWidget(menu);
    menuLayout->addWidget(inserisci);
    menuLayout->addWidget(salva);
    menuLayout->addWidget(colori);
}

void MainWindow::setWindowStyle(){

}
