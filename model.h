#ifndef MODEL_H
#define MODEL_H
#include "evento.h"
#include "lista.h"
#include "appuntamento.h"
#include "promemoria.h"
#include "impegno.h"
#include "compleanno.h"
#include "esporta.h"
#include "importa.h"
#include <vector>
#include <QDebug>
#include <iostream>
#include "smartevento.h"

class Model
{
private:
    Lista<SmartEvento> l;
    vector<SmartEvento> selezionati;
public:
    bool insert(Evento*);//prima verifica che non ci sia già l'evento poi inserisce nella lista l

    Lista<SmartEvento>::const_iterator search(Evento*) const;//ricerca se evento è già presente nella lista. nullptr se non lo trova, l'iteratore all'evento se lo trova.

    bool erase(Evento*);//cerca l'evento e se c'è cancella da iteratore. Se evento ricorrente cancella tutte le ricorrenze. True se ha successo, false altrimenti.

    /* inserisce in "selezionati" tutti gli eventi che si verificano nella data specificata e li ordina in base alla data e l'ora
     * l'ordine conta anche la data dell'evento, quindi da priorita' ad eventi ricorrenti creati in giorni precedenti*/
    void showEvent(const Data&);

    bool esporta();//scrive lista su file, true se ha successo, false altrimenti

    bool importa();//legge da file, true se ha successo, false altrimenti

    vector<SmartEvento> getSelezionati() const;
};

#endif // MODEL_H
