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

    vector<dataora> v;
    v.push_back(dataora());
    v.push_back(dataora());

    Evento* eA = new Appuntamento("conferenza",dataora(20,10,2010,10,10,10),dataora(20,10,2010,12,10,10),"Ufficio");
    Evento* eP = new Promemoria("Denti",dataora(3,5,2015,5,11,47),"Lavati i denti");
    Evento* eC = new Compleanno("???",dataora(7,9,2009,20,40,00),v,"Michele Baldisseri",data(7,9,1999));
    Evento* eI = new Impegno("conferenza",dataora(11,5,2020,11,11,11),dataora(11,5,2020,12,12,12),v);

    cout<<eA->descrizione()<<endl;
    cout<<eP->descrizione()<<endl;
    cout<<eC->descrizione()<<endl;
    cout<<eI->descrizione()<<endl;

return 0;
}
