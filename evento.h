#ifndef EVENTO_H
#define EVENTO_H
#include <iostream>
#include <sstream>
#include <iomanip>
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
    //costruttore con parametri
    Evento(const string& tit, const Dataora& di, const Color& c);

    //Descrizione delle informazioni basi, con formattazione per migliore lettura
    virtual string descrizioneMin() const = 0;
    //Stampa di tutte le informazioni
    virtual string descrizioneFull() const = 0;

    //setters and getters
    void setColore(const Color&);
    void setTitolo(const string&);
    void setDataInizio(const Dataora&);
    Color getColore() const;
    string getTitolo() const;
    Dataora getDataInizio() const;

    //operatori di confronto
    virtual bool operator==(const Evento&) const;
    virtual bool operator!=(const Evento&) const;

    //operatori di confronto per la Dataora iniziale, ma estendibili dalla classe eventoDurata che implementa una Dataora finale
    virtual bool operator>(const Evento&) const;
    virtual bool operator<(const Evento&) const;

    //distruttore
    virtual ~Evento() = default;

    //clone
    virtual Evento* clone() const = 0;


};

//richiama il metodo polimorfo
std::ostream& operator<<(std::ostream&, const Evento&);

#endif // EVENTO_H
