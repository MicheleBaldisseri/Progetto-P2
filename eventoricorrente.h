#ifndef EVENTORICORRENTE_H
#define EVENTORICORRENTE_H
#include "evento.h"
#include <vector>
using std::vector;

class EventoRicorrente : virtual public Evento{
private:
    //vettore di Date, poichè gli eventi ricorrenti mantengono l'orario dell'evento originale
    vector<Data> ricorrenze;
public:
    EventoRicorrente();
    EventoRicorrente(string, Dataora, vector<Data>, Color);

    virtual string descrizioneMin() const = 0;
    virtual string descrizioneFull() const = 0;

    void addRicorrenza(const Data&);
    //ritorna il vettore delle ricorrenze
    vector<Data>* getRicorrenze() const;

    virtual bool operator==(const Evento&) const;
    virtual bool operator!=(const Evento&) const;

    virtual ~EventoRicorrente()=default;
    virtual EventoRicorrente* clone() const = 0;
};

#endif // EVENTORICORRENTE_H
