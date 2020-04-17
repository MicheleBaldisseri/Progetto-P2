#ifndef EVENTORICORRENTE_H
#define EVENTORICORRENTE_H
#include "evento.h"
#include <vector>
using std::vector;

class EventoRicorrente : virtual public Evento{
private:
    vector<dataora> ricorrenze;
public:
    EventoRicorrente();
    EventoRicorrente(string, dataora, vector<dataora>, Color);

    virtual string descrizione() const = 0;

    void addRicorrenza(dataora);
    vector<dataora> getRicorrenze() const;

    virtual bool operator==(const Evento&) const;
    virtual bool operator!=(const Evento&) const;

    virtual ~EventoRicorrente()=default;
    virtual EventoRicorrente* clone() const = 0;
};

#endif // EVENTORICORRENTE_H
