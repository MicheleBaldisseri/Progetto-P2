#include "mainwindow.h"
#include <QApplication>
#include <iostream>
#include <vector>
#include "dataora.h"
#include "evento.h"
#include "appuntamento.h"
#include "promemoria.h"
#include "compleanno.h"
#include "impegno.h"

using std::vector;
using std::cout;
using std::endl;

int main(int argc, char *argv[])
{
/*
    QApplication a(argc, argv);
    MainWindow w;
    w.show();


    return a.exec();*/


    Evento* eA = new Appuntamento("Ex",Dataora(20,10,2010,10,10,10),Dataora(20,10,2010,12,10,10),"Ufficio");
    Evento* eA1 = new Appuntamento("Ex",Dataora(20,10,2010,10,10,10),Dataora(20,10,2010,11,10,10),"Ufficio");
    Evento* eP = new Promemoria("Denti",Dataora(3,5,2015,5,11,47),"Lavati i denti");
    Evento* eC = new Compleanno("Michele Baldisseri",Dataora(7,9,2009,20,40,00),Data(7,9,1999));
    Evento* eI = new Impegno("conferenza",Dataora(11,5,2020,11,11,11),Dataora(11,5,2020,12,12,12),giorno,1,5);

    cout<<*eA<<endl;
    cout<<*eP<<endl;
    cout<<*eC<<endl;
    cout<<*eI<<endl<<endl;

    cout<<eA->descrizioneMin()<<endl<<endl;
    cout<<eP->descrizioneMin()<<endl<<endl;
    cout<<eC->descrizioneMin()<<endl<<endl;
    cout<<eI->descrizioneMin()<<endl<<endl;

    cout<<(*eA1>*eA)<<endl<<endl;
    Dataora a(12,12,2020,23,30,0), b(12,4,2020,11,30,0);
    cout<<(a==b);

return 0;

}
