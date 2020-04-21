#ifndef EVENTO_H
#define EVENTO_H
#include <iostream>
#include <sstream>
#include "dataora.h"
using std::string;
using std::stringstream;

enum Color  {white, red, green, yellow, orange, black, blue, purple, grey};

class Evento{
private:
    string titolo;
    Dataora dataInizio;
    Color colore;
public:
    Evento();
    Evento(string, Dataora, Color);//costruttore per classi derivate

    virtual string descrizioneMin() const = 0;
    virtual string descrizioneFull() const = 0;

    void setColore(const Color&);
    Color getColore() const;
    string getTitolo() const;
    Dataora getDataInizio() const;

    virtual bool operator==(const Evento&) const;
    virtual bool operator!=(const Evento&) const;
    virtual bool operator>(const Evento&) const;//per la Dataora iniziale, ma estendibile dall'a classe con'evento con durata che implementa una Dataora finale
    virtual bool operator<(const Evento&) const;

    virtual ~Evento() = default;
    virtual Evento* clone() const = 0;
};

std::ostream& operator<<(std::ostream&, const Evento&);

#endif // EVENTO_H
