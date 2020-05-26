#ifndef COMPLEANNO_H
#define COMPLEANNO_H
#include "eventoricorrente.h"

class Compleanno : public EventoRicorrente {
private:
    Data dataNascita;
    static Color colorePred; //Colore predefinito, per creare tutti i tipi eventi con lo stesso colore
public:
    Compleanno();
    //parametro int: limite di creazione di ricorrenze
    Compleanno(const string& nome, const Dataora& di, const Data& dn, const int& limit=20, const Color& c =colorePred);

    string descrizioneMin() const;
    string descrizioneFull() const;
    Data getDataNascita() const;

    bool operator==(const Evento&) const;
    bool operator!=(const Evento&) const;

    ~Compleanno()=default;
    Compleanno* clone() const;
};

#endif // COMPLEANNO_H
