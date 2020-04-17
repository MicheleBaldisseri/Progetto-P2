#include "mainwindow.h"
#include <QApplication>
#include <iostream>
#include "data.h"
#include "orario.h"
#include "dataora.h"

int main(int argc, char *argv[])
{
    /*
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
    */
    dataora x(17,4,2020,23,12,30), y(17,4,2020,23,13,30);
    std::cout<<(y-x)<<std::endl;
    return 0;
}
