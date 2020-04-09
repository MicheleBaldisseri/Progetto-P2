#include "mainwindow.h"
#include <QApplication>
#include <iostream>
#include "data.h"

int main(int argc, char *argv[])
{
    /*
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
    */
    data oggi,domani(11,4,2020);
      std::string dataoggi=oggi.getData();
      std::cout<<dataoggi<<std::endl;
      oggi=domani;
      data prova(oggi);
      std::cout<<oggi<<prova<<std::endl;
}
