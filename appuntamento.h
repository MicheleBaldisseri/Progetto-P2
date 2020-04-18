#ifndef APPUNTAMENTO_H
#define APPUNTAMENTO_H
#include "eventodurata.h"

class Appuntamento : public EventoDurata{
private:
    string luogo;
    static Color colorePred;
public:
    Appuntamento();
    Appuntamento(string, dataora, dataora, string, Color=colorePred);

    virtual string descrizione() const;
    string getLuogo() const;

    bool operator==(const Evento&) const;
    bool operator!=(const Evento&) const;

    ~Appuntamento()=default;
    Appuntamento* clone() const;
};

Color Appuntamento::colorePred = green;

#endif // APPUNTAMENTO_H
