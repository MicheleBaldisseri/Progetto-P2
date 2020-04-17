#ifndef ORA_H
#define ORA_H
#include <iostream>
using std::ostream;

class orario{
public:
    orario(int o=0,int m=0,int s=0);
    orario(const orario& o);
    orario& operator=(const orario& o);
    ~orario();

    int getOre() const;
    int getMinuti() const;
    int getSecondi() const;

    void setOre(int o);
    void setMinuti(int m);
    void setSecondi(int s);

    void avanzaOre(int o);

    orario operator+(const orario& o) const;
    orario operator-(const orario& o) const;
    bool operator==(const orario& o) const;
    bool operator!=(const orario& o) const;
    bool operator<(const orario& o) const;
    bool operator>(const orario& o) const;



    operator int();

    //postfissi
    orario operator++(int);
    orario operator--(int); //sensato?
    //prefissi
    orario& operator++();
    orario& operator--();


private:
    int sec;
};
//overload operatore di output
std::ostream& operator<<(std::ostream&, const orario&);
#endif // ORA_H
