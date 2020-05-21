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
#include "lista.h"
#include "lista.cpp"
#include "model.h"
#include "controller.h"


using std::vector;
using std::cout;
using std::endl;

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);

    Model m;
   /* Controller c(&m);
    MainWindow w(&c);
    c.setView(&w);

    w.show();*/

    Evento* eA = new Appuntamento("Ex",Dataora(13,5,2020,10,10,10),Dataora(13,5,2020,12,10,10),"Ufficio");
    Evento* eP = new Promemoria("Denti",Dataora(14,5,2020,5,11,47),"Lavati i denti");
    Evento* eC = new Compleanno("Michele Baldisseri",Dataora(16,5,2020,00,00,00),Data(16,5,1999));
    Evento* eI = new Impegno("conferenza",Dataora(11,5,2020,11,11,11),Dataora(11,5,2020,12,12,12),giorno,2,3);

    /*m.insert(eA);
    m.insert(eP);
    m.insert(eC);
    m.insert(eI);*/


    //return a.exec();



    /*Evento* eA1 = new Appuntamento("Ex",Dataora(13,5,2020,10,10,10),Dataora(13,5,2020,12,10,10),"Ufficio");
    Evento* eC1 = new Compleanno("Miche Baldisseri",Dataora(7,9,2009,20,40,00),Data(7,9,1999));

    Evento* eI2 = new Impegno("conf",Dataora(11,5,2020,15,11,11),Dataora(11,5,2020,16,12,12),giorno,1,5);


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
    cout<<(a==b);*/
  


    Lista<Evento*> eventi;
   // m.insert(eI);
    //m.insert(eI2);
    //eventi.push_back(eA);
    //m.insert(eA1);
    //m.insert(eC1);
    //eventi.push_back(eP);
   // m.insert(eP);
   // m.insert(eA);

    //eventi.push_back(eC);
    //eventi.push_back(eI);
    //eventi.push_back(eC1);
    //eventi.push_back(eP);

    /*Lista<Evento*>::const_iterator cit=eventi.begin();
    //cout<<**cit<<endl;
    for(;cit!=eventi.end();cit++){
        cout<<**cit<<endl;
    }
    cout<<endl;
    cit=eventi.begin();
    cit++;

    cit=eventi.erase(cit);
    cit=eventi.erase(cit);

    Lista<Evento*>::const_iterator cit1=eventi.begin();
    for(;cit1!=eventi.end();cit1++){
        cout<<**cit1<<endl;
    }

    cout<<endl;
    Evento* got= eventi[0];
    cout<<*got<<endl<<endl;

    cit=eventi.begin();
    cit=eventi.erase(cit);
    cit=eventi.erase(cit);

    eventi.push_back(eI);
    eventi.push_back(eC);

    Lista<Evento*>::const_iterator cit2=eventi.begin();
    for(;cit2!=eventi.end();cit2++){
        cout<<**cit2<<endl;
    }

    Lista<Evento*> sel=m.showEvent(Data(7,9,2010));
    for(Lista<Evento*>::const_iterator cit2=sel.begin();cit2!=sel.end();cit2++){
        cout<<**cit2<<endl;
    }*/
    cout<<"export"<<endl;
   // cout<<m.esporta()<<endl;
    cout<<m.importa()<<endl;
    Lista<Evento*> sel=m.Getl();
    for(Lista<Evento*>::const_iterator cit2=sel.begin();cit2!=sel.end();cit2++){
        cout<<**cit2<<endl;
    }
return 0;

}
