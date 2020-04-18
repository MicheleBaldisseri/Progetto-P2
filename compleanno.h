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
    Compleanno(string, dataora, vector<dataora>, string, data, Color=colorePred);

    string descrizione() const;
    string getPersona() const;
    data getDataNascita() const;

    bool operator==(const Evento&) const;
    bool operator!=(const Evento&) const;

    ~Compleanno()=default;
    Compleanno* clone() const;
};

#endif // COMPLEANNO_H
