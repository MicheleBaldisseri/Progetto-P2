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
    //aggiorna la lista della vista tramite la data selezionata
    void updateList(const QDate& date);

    //salva gli eventi su file
    void exportEvents();

    //trasforma i dati della finestra in un oggetto da inserire o modificare
    void dataFromWindow(DatiEvento* obj,bool modifica);

    //elimina l'evento selezionato nella lista della vista (tramite la sua posizione)
    void eliminaEvento(const int& pos);

    //inizializza la modifica dell'evento selezionato nella lista della vista (tramite la sua posizione)
    void modificaEvento(const int& pos);
};

#endif // CONTROLLER_H
