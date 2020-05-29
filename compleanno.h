#ifndef COMPLEANNO_H
#define COMPLEANNO_H
#include "eventoricorrente.h"

class Compleanno : public EventoRicorrente {
private:
    Data dataNascita;
    static Color colorePred; //Colore predefinito, per creare tutti i tipi eventi con lo stesso colore
public:
    //costruttore di default
    Compleanno();
    //costruttore con parametri
    //parametro limit: limite di creazione di ricorrenze
    Compleanno(const string& nome, const Dataora& di, const Data& dn, const int& limit=20, const Color& c =colorePred);

    //metodi polimorfi
    string descrizioneMin() const;
    string descrizioneFull() const;

    //setters and getters
    void setDataNascita(const Data&);
    Data getDataNascita() const;

    //operatori di confronto
    bool operator==(const Evento&) const;
    bool operator!=(const Evento&) const;

    //distruttore
    ~Compleanno()=default;
    //clone
    Compleanno* clone() const;
};

#endif // COMPLEANNO_H
