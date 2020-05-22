#ifndef IMPEGNO_H
#define IMPEGNO_H
#include "eventodurata.h"
#include "eventoricorrente.h"

//definizione del tipo ModeRicorrenza, necessaria per la creazione degli eventi ricorrenti in modo automatico
enum ModeRicorrenza {giorno,settimana,mese};

class Impegno : public EventoDurata, public EventoRicorrente{
private:
    static Color colorePred; //Colore predefinito, per creare tutti i tipi eventi con lo stesso colore
public:
    Impegno();
    //costruttore con date ricorrenti già create
    Impegno(string, Dataora, Dataora, vector<Data>, Color=colorePred);
    /*
     * costruttore con date ricorrenti create automaticamente
     * ModeRicorrenza definisce il tipo di intervallo
     * interval indica ogni quanti intervalli
     * nRic indica quante ricorrenze scrivere
    */
    Impegno(string, Dataora, Dataora, ModeRicorrenza, int interval, int nRic, Color=colorePred);

    string descrizioneMin() const;
    string descrizioneFull() const;

    bool operator==(const Evento&) const;
    bool operator!=(const Evento&) const;

    ~Impegno()=default;
    Impegno* clone() const;
};



#endif // IMPEGNO_H
