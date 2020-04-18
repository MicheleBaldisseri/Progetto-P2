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
    dataora x(17,4,2020,22,0,0), y(19,4,2020,23,30,30);
    orario z(22,0,0), w(23,30,30);
    unsigned int prova=w-z;
    float sth=(y-x)/3600;
    std::cout<<(y-x)<<" "<<sth<<std::endl;
    return 0;
}
