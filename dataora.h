#ifndef DATAORA_H
#define DATAORA_H
#include "data.h"
#include "orario.h"
class Dataora: public Data, public Orario
{
public:
    Dataora();
    Dataora(int gg, int mm, int aa, int o, int m, int s);
    Dataora(const Dataora& d);
    Dataora(const Data& d, const Orario& o);
    //distruttore, assegnazione, Dataora(Data,Ora)

    //overload operatori
    unsigned int operator-(const Dataora& d) const;
    bool operator==(const Dataora& d) const;
    bool operator!=(const Dataora& d) const;
    bool operator<(const Dataora& d) const;
    bool operator>(const Dataora& d) const;

    static double secondsToHours(unsigned int s);
    static double secondsToMinutes(unsigned int s);
};
//overload operatore di output
std::ostream& operator<<(std::ostream& os, const Dataora& d);
#endif // DATAORA_H
