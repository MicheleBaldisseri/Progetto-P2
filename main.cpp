#include "mainwindow.h"
#include <QApplication>
#include "model.h"
#include "controller.h"

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
