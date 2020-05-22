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
    Controller c(&m);
    MainWindow w(&c);
    c.setView(&w);

    w.show();

    m.importa();

    w.updateList();
    return a.exec();

return 0;

}
