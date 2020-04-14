#include "dataora.h"


dataora::dataora():data(),orario(){}

dataora::dataora(int gg, int mm, int aa, int o, int m, int s):data(gg,mm,aa),orario(o,m,s){}

void dataora::stampaData()
{

}

std::ostream &operator<<(std::ostream &os, const dataora &d)
{
    std::cout<<d.getGiorno()<<"/"<<d.getMese()<<"/"<<d.getAnno()<<" "<<d.getOre()<<":"<<d.getMinuti()<<":"<<d.getSecondi()<<std::endl;
    return os;
}
