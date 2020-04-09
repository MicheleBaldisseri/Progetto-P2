#ifndef ORA_H
#define ORA_H
#include <iostream>
using std::ostream;

class orario{
private:
    int sec;//minuti,ore,secondi?
public:
    orario(int=0,int=0,int=0);
    orario(const orario&);
    orario& operator=(const orario&);
    ~orario();

    int getOre() const;
    int getMinuti() const;
    int getSecondi() const;

    void setOre();
    void setMinuti();
    void setSecondi();

    operator int();
    orario operator+();
    orario operator-();
    //postfissi
    orario operator++(int);
    orario operator--(int); //sensato?
    //prefissi
    orario& operator++();
    orario& operator--();
    bool operator==(const orario&);
    bool operator!=(const orario&);
    bool operator<(const orario&);
    bool operator>(const orario&);
};
//overload operatore di output
std::ostream& operator<<(std::ostream&, const orario&);
#endif // ORA_H
