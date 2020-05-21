#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include "datievento.h"
#include "evento.h"
#include "impegno.h"
#include "mainwindow.h"
#include "model.h"
#include "promemoria.h"
#include "appuntamento.h"
#include "compleanno.h"

class Controller : public QObject
{
    Q_OBJECT
private:
    MainWindow* view;
    Model* model;

public:
    explicit Controller(Model* model, QObject *parent = nullptr);
    void setView(MainWindow* v);

public slots:
    void updateList(const QDate& date);
    void exportEvents();
    void dataFromWindow(DatiEvento* obj,bool modifica);
    void eliminaEvento(const int& pos);
    void modificaEvento(const int& pos);
};

#endif // CONTROLLER_H
