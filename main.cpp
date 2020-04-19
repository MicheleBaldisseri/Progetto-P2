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
    Dataora x(17,4,2020,0,0,0), y(18,4,2020,2,30,0);
    Orario z(22,0,0), w(23,30,30);
    std::cout<<x<<std::endl;
    std::cout<<(y-x)<<" "<<Dataora::secondsToHours(y-x)<<" "<< x<<std::endl;
    return 0;
}
