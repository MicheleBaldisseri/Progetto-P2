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
    dataora x(17,4,2020,23,0,0), y(18,4,2020,1,0,0);
    orario z(22,0,0), w(23,30,30);

    std::cout<<(y-x)<<" "<<dataora::secondsToHours(y-x)<<std::endl;
    return 0;
}
