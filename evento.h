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
    Evento(string, dataora, Color=white);//costruttore per classi derivate

    virtual string descrizione() const = 0;

    virtual Color setColore() const = 0;
    Color getColore() const;
    string getTitolo() const;
    dataora getDataora() const;

    virtual bool operator==(const Evento& e) const;

    virtual ~Evento(){}
    virtual Evento* clone() const = 0;
};

#endif // EVENTO_H
