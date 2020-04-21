#ifndef PROMEMORIA_H
#define PROMEMORIA_H
#include "evento.h"

class Promemoria : public Evento {
private:
    string desc;
    static Color colorePred;
public:
    Promemoria();
    Promemoria(string, Dataora, string, Color=colorePred);

    string descrizioneMin() const;
    string descrizioneFull() const;
    string getDesc() const;

    bool operator==(const Evento&) const;
    bool operator!=(const Evento&) const;

    ~Promemoria()=default;
    Promemoria* clone() const;
};

#endif // PROMEMORIA_H
