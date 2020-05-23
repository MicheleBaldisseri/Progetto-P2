#ifndef SMARTEVENTO_H
#define SMARTEVENTO_H

#include "evento.h"

class SmartEvento
{
private:
    Evento* ptr; //puntatore (super)polimorfo
public:
    SmartEvento(Evento* e); //convertitore Evento* => SmartEvento
    SmartEvento(const SmartEvento& s);
    SmartEvento& operator=(const SmartEvento& s);
    Evento& operator*() const;
    Evento* operator->() const;
    bool operator==(const SmartEvento& x) const;
    ~SmartEvento();
};

#endif // SMARTEVENTO_H
