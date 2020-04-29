#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QWidget(parent) {
    mainLayout = new QVBoxLayout(this);
    itemLayout = new QHBoxLayout();
    buttonLayout = new QVBoxLayout();

    addMainItems();

    addButtons();

    setWindowStyle();

    setLayout(mainLayout);
}

void MainWindow::addMainItems(){
    //mainLayout->addSomething sopra gli item
    mainLayout->addLayout(itemLayout);
    itemLayout->addLayout(buttonLayout);

    QFrame *line1 = new QFrame();
    line1->setFrameShape(QFrame::VLine);
    itemLayout->addWidget(line1);

    QCalendarWidget* calendar = new QCalendarWidget(); //si può spostare come campo privato se necessario
    itemLayout->addWidget(calendar);

    QFrame *line2 = new QFrame();
    line2->setFrameShape(QFrame::VLine);
    itemLayout->addWidget(line2);

    QListView* list = new QListView();  //si può spostare come campo privato se necessario
    itemLayout->addWidget(list);
}

void MainWindow::addButtons(){


}

void MainWindow::setWindowStyle(){

}
