#ifndef COMPLEANNO_H
#define COMPLEANNO_H
#include "eventoricorrente.h"

class Compleanno : public EventoRicorrente {
private:
    Data dataNascita;
    static Color colorePred;
public:
    Compleanno();
    Compleanno(string, Dataora, Data, int, Color=colorePred);

    string descrizioneMin() const;
    string descrizioneFull() const;
    Data getDataNascita() const;

    bool operator==(const Evento&) const;
    bool operator!=(const Evento&) const;

    ~Compleanno()=default;
    Compleanno* clone() const;
};

#endif // COMPLEANNO_H
