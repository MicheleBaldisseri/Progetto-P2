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
    data oggi,domani(11,4,2021);
      std::string dataoggi=oggi.getData();
      std::cout<<dataoggi<<std::endl;
      oggi=domani;
      data prova(oggi);
      std::cout<<oggi<<prova<<std::endl;
      if(domani.bisestile()) std::cout<<"bisestile"<<std::endl;
      else std::cout<<"non bisestile"<<std::endl;

}
