#ifndef DATAORA_H
#define DATAORA_H
#include "data.h"
#include "orario.h"
class dataora: public data, public orario
{
public:
    dataora();
    dataora(int gg, int mm, int aa, int o, int m, int s);
    dataora(const dataora& d);

    //overload operatori
    dataora operator+(const dataora& d) const;
    unsigned int operator-(const dataora& d) const;
    bool operator==(const dataora& d) const;
    bool operator!=(const dataora& d) const;
    bool operator<(const dataora& d) const;
    bool operator>(const dataora& d) const;

    static double secondsToHours(unsigned int s);

private:

};
//overload operatore di output
std::ostream& operator<<(std::ostream& os, const dataora& d);
#endif // DATAORA_H
