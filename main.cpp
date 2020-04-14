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
    data oggi,domani(11,20,2021);
      std::string dataoggi=oggi.getData();
      std::cout<<dataoggi<<std::endl;
      oggi=domani;
      int ggmese=oggi.getGiorniMese();
      data prova(oggi);
      std::cout<<oggi<<prova<<std::endl;
      std::cout<<"giorni che ha il mese di aprile "<<ggmese<<std::endl;
      oggi.avanzaGiorni(20);
      domani.avanzaMesi(11);
      std::cout<<"aggiungo 20 giorni alla variabile oggi "<<oggi<<std::endl;
      std::cout<<"aggiungo 11 mesi alla variabile domani "<<domani<<std::endl;
      if(domani.bisestile()) std::cout<<"bisestile"<<std::endl;
      else std::cout<<"non bisestile"<<std::endl;
      orario o(22,8,15);
      dataora x(13,4,2020,22,8,15);
      x.avanzaOre(2);
      x.avanzaGiorni(1);
      std::cout<<x<<std::endl;
    return 0;
}
