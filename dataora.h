#ifndef DATAORA_H
#define DATAORA_H
#include "data.h"
#include "orario.h"
class dataora: public data, public orario
{
public:
    dataora();
    dataora(int gg, int mm, int aa, int o, int m, int s);
    void stampaData();
    bool operator==(const dataora&) const{return true;}
    bool operator!=(const dataora&) const{return true;}
    bool operator>(const dataora&) const{return true;}
    bool operator<(const dataora&) const{return true;}
};
//overload operatore di output
std::ostream& operator<<(std::ostream& os, const dataora& d);
#endif // DATAORA_H
