#ifndef ORA_H
#define ORA_H
#include <iostream>
using std::ostream;

class Orario{
public:
    /**
     * @brief costruttore completo
     * @param ore
     * @param minuti
     * @param secondi
     */
    Orario(const int& o=0,const int& m=0,const int& s=0);
    /**
     * @brief costruttore 1 param.
     * @param secondi
     */
    Orario(const unsigned int& s);
    //costruttore di copia
    Orario(const Orario& o);
    //overload operatore assegnazione
    Orario& operator=(const Orario& o);
    //distruttore
    ~Orario();

    //getters
    int getOre() const;
    int getMinuti() const;
    int getSecondi() const;
    std::string getOrario() const;
    unsigned int getCampoDati() const;

    //setters
    void setOre(const int& o);
    void setMinuti(const int& m);
    void setSecondi(const int& s);

    /**
     * @brief avanza le ore dell'obj d'invocazione
     * @param ore da avanzare
     */
    void avanzaOre(int o);

    //overload operatori
    Orario operator-(const Orario& o) const; //ritorna la differenza in "durata"
    bool operator==(const Orario& o) const;
    bool operator!=(const Orario& o) const;
    bool operator<(const Orario& o) const;
    bool operator>(const Orario& o) const;
private:
    unsigned int sec;
};

//overload operatore di output
std::ostream& operator<<(std::ostream&, const Orario&);

#endif // ORA_H
