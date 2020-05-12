#include "controller.h"

Controller::Controller(Model* m, QObject* parent)
        : QObject(parent), view(nullptr), model(m) {}

void Controller::setView(MainWindow* v) { view = v; }
