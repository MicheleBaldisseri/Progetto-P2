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
};
//overload operatore di output
std::ostream& operator<<(std::ostream& os, const dataora& d);
#endif // DATAORA_H
