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
    Dataora x(19,4,2020,23,0,0), y(19,4,2020,23,30,0);
    Orario z(23,0,0), w(1,30,0), prova=z-w;
    Data a(17,4,2020), b(18,4,2020);
    std::cout<<(y-x)<<" "<<Dataora::secondsToMinutes(y-x)<<std::endl;
    return 0;
}
