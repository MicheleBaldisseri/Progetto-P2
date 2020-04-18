#ifndef IMPEGNO_H
#define IMPEGNO_H
#include "eventodurata.h"
#include "eventoricorrente.h"

class Impegno : public EventoDurata, public EventoRicorrente{
private:
    static Color colorePred;
public:
    Impegno();
    Impegno(string, dataora, dataora, vector<dataora>, Color=colorePred);

    string descrizione() const;

    bool operator==(const Evento&) const;
    bool operator!=(const Evento&) const;

    ~Impegno()=default;
    Impegno* clone() const;
};

Color Impegno::colorePred = blue;

#endif // IMPEGNO_H
