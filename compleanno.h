#ifndef COMPLEANNO_H
#define COMPLEANNO_H
#include "eventoricorrente.h"

class Compleanno : public EventoRicorrente {
private:
    string persona;
    data dataNascita;
    static Color colorePred;
public:
    Compleanno();
    Compleanno(string, dataora, vector<dataora> string, data, Color=colorePred);

    string descrizione() const;

    bool operator==(const Evento&) const;
    bool operator!=(const Evento&) const;

    ~Compleanno()=default;
    Compleanno* clone() const;
};

Color Compleanno::colorePred = red;

#endif // COMPLEANNO_H
