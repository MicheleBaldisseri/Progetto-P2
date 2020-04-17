#ifndef PROMEMORIA_H
#define PROMEMORIA_H
#include "evento.h"

class Promemoria : public Evento {
private:
    string desc;
    static Color colorePred;
public:
    Promemoria();
    Promemoria(string, dataora, Color=colorePred);

    string descrizione() const;

    bool operator==(const Evento&) const;
    bool operator!=(const Evento&) const;

    ~Promemoria()=default;
    Promemoria* clone() const;
};

Color Promemoria::colorePred = yellow;

#endif // PROMEMORIA_H
