#ifndef DATAORA_H
#define DATAORA_H
#include "data.h"
#include "orario.h"
class Dataora: public Data, public Orario
{
public:
    //costruttore di default
    Dataora();
    /**
     * @brief costruttore completo
     * @param giorno
     * @param mese
     * @param anno
     * @param ore
     * @param minuti
     * @param secondi
     */
    Dataora(int gg, int mm, int aa, int o, int m, int s);
    //costruttore di copia
    Dataora(const Dataora& d);
    //costruttore data+orario
    Dataora(const Data& d, const Orario& o);
    //distruttore
    ~Dataora()=default;

    //overload operatori
    bool operator==(const Dataora& d) const;
    bool operator!=(const Dataora& d) const;
    bool operator<(const Dataora& d) const;
    bool operator>(const Dataora& d) const;
    /**
     * @return differenza tra due dataora come durata espressa in secondi
     */
    unsigned int operator-(const Dataora& d) const;

    /**
     * @brief converte secondi->ore
     * @param secondi da convertire
     * @return ore
     */
    static double secondsToHours(unsigned int s);
    /**
     * @brief converte secondi->minuti
     * @param secondi da convertire
     * @return minuti
     */
    static double secondsToMinutes(unsigned int s);
};

//overload operatore di output
std::ostream& operator<<(std::ostream& os, const Dataora& d);

#endif // DATAORA_H
