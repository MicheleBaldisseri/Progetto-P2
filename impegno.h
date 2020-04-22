#ifndef IMPEGNO_H
#define IMPEGNO_H
#include "eventodurata.h"
#include "eventoricorrente.h"

enum ModeRicorrenza {giorno,settimana,mese};

class Impegno : public EventoDurata, public EventoRicorrente{
private:
    static Color colorePred;
public:
    Impegno();
    Impegno(string, Dataora, Dataora, vector<Data>, Color=colorePred);
    Impegno(string, Dataora, Dataora, ModeRicorrenza, int, int, Color=colorePred);

    string descrizioneMin() const;
    string descrizioneFull() const;

    bool operator==(const Evento&) const;
    bool operator!=(const Evento&) const;

    ~Impegno()=default;
    Impegno* clone() const;
};



#endif // IMPEGNO_H
