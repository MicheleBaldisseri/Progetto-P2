#ifndef COMPLEANNO_H
#define COMPLEANNO_H
#include "eventoricorrente.h"

class Compleanno : public EventoRicorrente {
private:
    data dataNascita;
    static Color colorePred;
public:
    Compleanno();
    Compleanno(string, dataora, vector<dataora>, data, Color=colorePred);

    string descrizioneMin() const;
    string descrizioneFull() const;
    data getDataNascita() const;

    bool operator==(const Evento&) const;
    bool operator!=(const Evento&) const;

    ~Compleanno()=default;
    Compleanno* clone() const;
};

#endif // COMPLEANNO_H
