#include "dataora.h"


dataora::dataora():data(),orario(){}

dataora::dataora(int gg, int mm, int aa, int o, int m, int s):data(gg,mm,aa),orario(o,m,s){}

dataora::dataora(const dataora &d):data(d.getGiorno(),d.getMese(),d.getAnno()), orario(d.getOre(),d.getMinuti(),d.getSecondi()){}

bool dataora::operator==(const dataora &d) const
{
    orario o1(getOre(),getMinuti(),getSecondi());
    data d1(getGiorno(),getMese(),getAnno());
    orario o2(d.getOre(),d.getMinuti(),d.getSecondi());
    data d2(d.getGiorno(),d.getMese(),d.getAnno());
    return d1==d2 && o1==o2;
}

bool dataora::operator!=(const dataora &d) const
{
    orario o1(getOre(),getMinuti(),getSecondi());
    data d1(getGiorno(),getMese(),getAnno());
    orario o2(d.getOre(),d.getMinuti(),d.getSecondi());
    data d2(d.getGiorno(),d.getMese(),d.getAnno());
    return d1!=d2 || o1!=o2;
}

bool dataora::operator<(const dataora &d) const
{
    orario o1(getOre(),getMinuti(),getSecondi());
    data d1(getGiorno(),getMese(),getAnno());
    orario o2(d.getOre(),d.getMinuti(),d.getSecondi());
    data d2(d.getGiorno(),d.getMese(),d.getAnno());
    return d1<d2? true : (d1==d2? (o1<o2? true : false ) : false );
}

bool dataora::operator>(const dataora &d) const
{
    orario o1(getOre(),getMinuti(),getSecondi());
    data d1(getGiorno(),getMese(),getAnno());
    orario o2(d.getOre(),d.getMinuti(),d.getSecondi());
    data d2(d.getGiorno(),d.getMese(),d.getAnno());
    return d1>d2? true : (d1==d2? (o1>o2? true : false ) : false );
}

unsigned int dataora::operator-(const dataora &d) const
{
    data d1(getGiorno(),getMese(),getAnno()),
            d2(d.getGiorno(),d.getMese(),d.getAnno());
    orario o1(getOre(),getMinuti(),getSecondi()),
            o2(d.getOre(),d.getMinuti(),d.getSecondi());
    unsigned int gg=d1-d2, sec=o1-o2;
    sec= sec+ (gg*86400);
    return sec;

}

double dataora::secondsToHours(unsigned int s)
{
    double sec=s, secInHour=3600;
    return (sec/secInHour);
}

std::ostream &operator<<(std::ostream &os, const dataora &d)
{
    std::cout<<d.getGiorno()<<"/"<<d.getMese()<<"/"<<d.getAnno()<<" "<<d.getOre()<<":"<<d.getMinuti()<<":"<<d.getSecondi()<<std::endl;
    return os;
}
