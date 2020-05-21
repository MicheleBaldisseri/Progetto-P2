#ifndef PROMEMORIA_H
#define PROMEMORIA_H
#include "evento.h"

class Promemoria : public Evento {
private:
    string desc; //descrizione più estesa
    static Color colorePred; //Colore predefinito, per creare tutti i tipi eventi con lo stesso colore
public:
    Promemoria();
    Promemoria(string, Dataora, string, Color=colorePred);

    string descrizioneMin() const;
    string descrizioneFull() const;
    string getDesc() const;
    void toExp(QXmlStreamWriter&);
    Evento* fromImp(QXmlStreamReader&);

    bool operator==(const Evento&) const;
    bool operator!=(const Evento&) const;

    ~Promemoria()=default;
    Promemoria* clone() const;
};

#endif // PROMEMORIA_H
