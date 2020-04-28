#ifndef DATAORA_H
#define DATAORA_H
#include "data.h"
#include "orario.h"
class Dataora: public Data, public Orario
{
public:
    //costruttore di default
    Dataora();
    //costruttore con tutti i parametri
    Dataora(int gg, int mm, int aa, int o, int m, int s);
    //costruttore di copia
    Dataora(const Dataora& d);
    //costruttore data+orario
    Dataora(const Data& d, const Orario& o);
    //distruttore
    ~Dataora()=default;
    //assegnazione
    //Dataora& operator=(const Dataora& d);???

    //overload operatori
    bool operator==(const Dataora& d) const;
    bool operator!=(const Dataora& d) const;
    bool operator<(const Dataora& d) const;
    bool operator>(const Dataora& d) const;
    //l'operator- ritorna una durata espressa in secondi, nonchè differenza tra due dataora
    unsigned int operator-(const Dataora& d) const;

    static double secondsToHours(unsigned int s);
    static double secondsToMinutes(unsigned int s);
};
//overload operatore di output
std::ostream& operator<<(std::ostream& os, const Dataora& d);
#endif // DATAORA_H
