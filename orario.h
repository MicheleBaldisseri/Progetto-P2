#ifndef ORA_H
#define ORA_H
#include <iostream>
using std::ostream;

class Orario{
public:
    Orario(int o=0,int m=0,int s=0);
    Orario(unsigned int s);
    Orario(const Orario& o);
    Orario& operator=(const Orario& o);
    ~Orario();

    int getOre() const;
    int getMinuti() const;
    int getSecondi() const;

    void setOre(int o);
    void setMinuti(int m);
    void setSecondi(int s);

    void avanzaOre(int o);

    Orario operator-(const Orario& o) const;
    bool operator==(const Orario& o) const;
    bool operator!=(const Orario& o) const;
    bool operator<(const Orario& o) const;
    bool operator>(const Orario& o) const;

    unsigned int getCampoDati() const;
private:
    unsigned int sec;
};
//overload operatore di output
std::ostream& operator<<(std::ostream&, const Orario&);
#endif // ORA_H
