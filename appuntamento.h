
#ifndef APPUNTAMENTO_H
#define APPUNTAMENTO_H
#include "eventodurata.h"

class Appuntamento : public EventoDurata{
private:
    string luogo;
    static Color colorePred; //Colore predefinito, per creare tutti i tipi eventi con lo stesso colore
public:
    //costruttore di default
    Appuntamento();
    //costruttore con parametri
    Appuntamento(const string& tit, const Dataora& di, const Dataora& df, const string& l, const Color& c =colorePred);

    //metodi polimorfi
    string descrizioneMin() const;
    string descrizioneFull() const;

    //setters and getters
    void setLuogo(const string&);
    string getLuogo() const;

    //operatori di confronto
    bool operator==(const Evento&) const;
    bool operator!=(const Evento&) const;

    //distruttore
    ~Appuntamento()=default;
    //clone
    Appuntamento* clone() const;
};

#endif // APPUNTAMENTO_H
