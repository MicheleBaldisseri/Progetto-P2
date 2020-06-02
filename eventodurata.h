#ifndef EVENTODURATA_H
#define EVENTODURATA_H
#include "evento.h"

class EventoDurata : virtual public Evento{
private:
    Dataora dataFine; //data finale
public:
    //costruttore di default
    EventoDurata();
    //costruttore con parametri
    EventoDurata(const string& tit, const Dataora& di, const Dataora& df, const Color& c);

    //metodi polimorfi
    virtual string descrizioneMin() const = 0;
    virtual string descrizioneFull() const = 0;

    //setters and getters
    void setDataFine(const Dataora&);
    Dataora getDataFine() const;

    //ritorna la durata dell'evento in secondi
    int durata() const;

    //operators
    virtual bool operator==(const Evento&) const;
    virtual bool operator!=(const Evento&) const;

    //controlla anche la datafinale
    virtual bool operator>(const Evento&) const;
    virtual bool operator<(const Evento&) const;

    //distruttore
    virtual ~EventoDurata()=default;
    //clone
    virtual EventoDurata* clone() const = 0;
};

#endif // EVENTODURATA_H
