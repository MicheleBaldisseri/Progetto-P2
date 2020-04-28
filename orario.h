#ifndef ORA_H
#define ORA_H
#include <iostream>
using std::ostream;

class Orario{
public:
    //costruttore ore-min-sec
    Orario(int o=0,int m=0,int s=0);
    //costruttore sec
    Orario(unsigned int s);
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

    unsigned int getCampoDati() const;//meglio mettere in protected?

    //setters
    void setOre(int o);
    void setMinuti(int m);
    void setSecondi(int s);

    //avanza di "o" ore l'oggetto d'invocazione
    void avanzaOre(int o);

    //overload operatori
    Orario operator-(const Orario& o) const;
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
