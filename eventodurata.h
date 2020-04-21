#ifndef EVENTODURATA_H
#define EVENTODURATA_H
#include "evento.h"

class EventoDurata : virtual public Evento{
private:
    Dataora dataFine;
public:
    EventoDurata();
    EventoDurata(string, Dataora, Dataora, Color);

    virtual string descrizioneMin() const = 0;
    virtual string descrizioneFull() const = 0;

    Dataora getDataFine() const;
    int durata() const;

    virtual bool operator==(const Evento&) const;
    virtual bool operator!=(const Evento&) const;
    virtual bool operator>(const Evento&) const;
    virtual bool operator<(const Evento&) const;

    virtual ~EventoDurata()=default;
    virtual EventoDurata* clone() const = 0;
};

#endif // EVENTODURATA_H
