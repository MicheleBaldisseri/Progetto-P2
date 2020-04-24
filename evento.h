#ifndef EVENTO_H
#define EVENTO_H
#include <iostream>
#include <sstream>
#include "dataora.h"
using std::string;
using std::stringstream;

//definizione del tipo Color, che rappresenta i colori dei vari eventi (per differenziare i tipi diversi nella vista)
enum Color  {white, red, green, yellow, orange, black, blue, purple, grey};

class Evento{
private:
    string titolo;
    Dataora dataInizio;
    Color colore;
public:
    //costruttore standard
    Evento();
    //costruttore con campi classico per classi derivate
    Evento(string, Dataora, Color);

    //Descrizione delle informazioni basi, con formattazione e descrizione per migliore lettura
    virtual string descrizioneMin() const = 0;
    //Stampa di tutte le informazioni
    virtual string descrizioneFull() const = 0;


    void setColore(const Color&);
    Color getColore() const;
    string getTitolo() const;
    Dataora getDataInizio() const;

    //operatori di confronto
    virtual bool operator==(const Evento&) const;
    virtual bool operator!=(const Evento&) const;

    //operatori di confronto per la Dataora iniziale, ma estendibili dalla classe eventoDurata che implementa una Dataora finale
    virtual bool operator>(const Evento&) const;
    virtual bool operator<(const Evento&) const;

    virtual ~Evento() = default;
    virtual Evento* clone() const = 0;
};

//richiama il metodo polimorfo
std::ostream& operator<<(std::ostream&, const Evento&);

#endif // EVENTO_H
