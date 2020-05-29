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
    //costruttore di default
    EventoRicorrente();
    //costruttore con parametri
    EventoRicorrente(const string& tit, const Dataora& di, const vector<Data>& ric, const Color& c);

    //metodi polimorfi
    virtual string descrizioneMin() const = 0;
    virtual string descrizioneFull() const = 0;

    //aggiunge le ricorrenze uno a uno nel vettore delle ricorrenze
    void addRicorrenza(const Data&);
    //pulisce il vettore delle ricorrenze
    void clearRicorrenze();

    //setters and getters
    void setRicorrenze(const vector<Data>&);
    vector<Data> getRicorrenze() const;

    //operatori di confronto
    virtual bool operator==(const Evento&) const;
    virtual bool operator!=(const Evento&) const;

    //distruttore
    virtual ~EventoRicorrente()=default;
    //clone
    virtual EventoRicorrente* clone() const = 0;
};

#endif // EVENTORICORRENTE_H
