#ifndef IMPEGNO_H
#define IMPEGNO_H
#include "eventodurata.h"
#include "eventoricorrente.h"

class Impegno : public EventoDurata, public EventoRicorrente{
public:
    Impegno();
};

#endif // IMPEGNO_H
