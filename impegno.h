#ifndef IMPEGNO_H
#define IMPEGNO_H
#include "eventodurata.h"
#include "eventoricorrente.h"

class Impegno : public EventoDurata, public EventoRicorrente{
private:
    static Color colorePred;
public:
    Impegno();
    Impegno(string, Dataora, Dataora, vector<Data>, Color=colorePred);

    string descrizioneMin() const;
    string descrizioneFull() const;

    bool operator==(const Evento&) const;
    bool operator!=(const Evento&) const;

    ~Impegno()=default;
    Impegno* clone() const;
};



#endif // IMPEGNO_H
