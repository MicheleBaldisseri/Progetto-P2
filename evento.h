#ifndef EVENTO_H
#define EVENTO_H
#include <iostream>
#include "dataora.h"
using std::string;

enum Color  {white, red, green, yellow, orange, black, blue, purple, grey};

class Evento{
private:
    string titolo;
    dataora dataInizio;
    Color colore;
public:
    Evento();
    Evento(string, dataora, Color);//costruttore per classi derivate

    virtual string descrizione() const = 0;

    void setColore(const Color&);
    Color getColore() const;
    string getTitolo() const;
    dataora getDataInizio() const;

    virtual bool operator==(const Evento&) const;
    virtual bool operator!=(const Evento&) const;
    virtual bool operator>(const Evento&) const;//per la Dataora iniziale, ma estendibile dall'a classe con'evento con durata che implementa una Dataora finale
    virtual bool operator<(const Evento&) const;

    virtual ~Evento() = default;
    virtual Evento* clone() const = 0;
};

#endif // EVENTO_H
