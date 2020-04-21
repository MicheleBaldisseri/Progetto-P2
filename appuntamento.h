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

    string descrizioneMin() const;
    string descrizioneFull() const;
    string getLuogo() const;

    bool operator==(const Evento&) const;
    bool operator!=(const Evento&) const;

    ~Appuntamento()=default;
    Appuntamento* clone() const;
};

#endif // APPUNTAMENTO_H
