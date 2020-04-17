#ifndef EVENTODURATA_H
#define EVENTODURATA_H
#include "evento.h"

class EventoDurata : virtual public Evento{
private:
    dataora dataFine;
public:
    EventoDurata();
    EventoDurata(string, dataora, dataora, Color);

    virtual string descrizione() const = 0;

    dataora getDataFine() const;
    int durata() const;

    virtual bool operator==(const Evento&) const;
    virtual bool operator!=(const Evento&) const;
    virtual bool operator>(const Evento&) const;
    virtual bool operator<(const Evento&) const;

    virtual ~EventoDurata()=default;
    virtual EventoDurata* clone() const = 0;
};

#endif // EVENTODURATA_H
