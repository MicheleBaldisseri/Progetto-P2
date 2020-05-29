#ifndef PROMEMORIA_H
#define PROMEMORIA_H
#include "evento.h"

class Promemoria : public Evento {
private:
    string desc; //descrizione più estesa
    static Color colorePred; //Colore predefinito, per creare tutti i tipi eventi con lo stesso colore
public:
    //costruttore di default
    Promemoria();
    //costruttore con parametri
    Promemoria(const string& tit, const Dataora& di, const string& d, const Color& c =colorePred);

    //metodi polimorfi di stampa
    string descrizioneMin() const;
    string descrizioneFull() const;

    //setters and getters
    void setDesc(const string&);
    string getDesc() const;

    //operatori di confronto
    bool operator==(const Evento&) const;
    bool operator!=(const Evento&) const;

    //distruttore
    ~Promemoria()=default;
    //clone
    Promemoria* clone() const;
};

#endif // PROMEMORIA_H
