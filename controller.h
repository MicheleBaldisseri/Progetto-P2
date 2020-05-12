#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include "mainwindow.h"
#include "model.h"

class Controller : public QObject
{
    Q_OBJECT
private:
    MainWindow* view;
    Model* model;

public:
    explicit Controller(Model* model, QObject *parent = nullptr);

    void setView(MainWindow* v);
};

#endif // CONTROLLER_H
