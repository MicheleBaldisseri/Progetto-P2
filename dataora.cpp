#include "dataora.h"


Dataora::Dataora():Data(),Orario(){}

Dataora::Dataora(int gg, int mm, int aa, int o, int m, int s):Data(gg,mm,aa),Orario(o,m,s){}

Dataora::Dataora(const Dataora &d):Data(d.getGiorno(),d.getMese(),d.getAnno()), Orario(d.getOre(),d.getMinuti(),d.getSecondi()){}

bool Dataora::operator==(const Dataora &d) const
{
    Orario o1(getOre(),getMinuti(),getSecondi());
    Data d1(getGiorno(),getMese(),getAnno());
    Orario o2(d.getOre(),d.getMinuti(),d.getSecondi());
    Data d2(d.getGiorno(),d.getMese(),d.getAnno());
    return d1==d2 && o1==o2;
}

bool Dataora::operator!=(const Dataora &d) const
{
    Orario o1(getOre(),getMinuti(),getSecondi());
    Data d1(getGiorno(),getMese(),getAnno());
    Orario o2(d.getOre(),d.getMinuti(),d.getSecondi());
    Data d2(d.getGiorno(),d.getMese(),d.getAnno());
    return d1!=d2 || o1!=o2;
}

bool Dataora::operator<(const Dataora &d) const
{
    Orario o1(getOre(),getMinuti(),getSecondi());
    Data d1(getGiorno(),getMese(),getAnno());
    Orario o2(d.getOre(),d.getMinuti(),d.getSecondi());
    Data d2(d.getGiorno(),d.getMese(),d.getAnno());
    return d1<d2? true : (d1==d2? (o1<o2? true : false ) : false );
}

bool Dataora::operator>(const Dataora &d) const
{
    Orario o1(getOre(),getMinuti(),getSecondi());
    Data d1(getGiorno(),getMese(),getAnno());
    Orario o2(d.getOre(),d.getMinuti(),d.getSecondi());
    Data d2(d.getGiorno(),d.getMese(),d.getAnno());
    return d1>d2? true : (d1==d2? (o1>o2? true : false ) : false );
}

unsigned int Dataora::operator-(const Dataora &d) const
{
    Data d1(getGiorno(),getMese(),getAnno()),
            d2(d.getGiorno(),d.getMese(),d.getAnno());
    Orario o1(getOre(),getMinuti(),getSecondi()),
            o2(d.getOre(),d.getMinuti(),d.getSecondi());
    unsigned int gg=d1-d2, sec=o1-o2;
    sec= sec+ (gg*86400);
    return sec;

}

double Dataora::secondsToHours(unsigned int s)
{
    double sec=s, secInHour=3600;
    return (sec/secInHour);
}

std::ostream &operator<<(std::ostream &os, const Dataora &d)
{
    std::cout<<d.getStringGs(d.getGiornoSettimana())<<" "<<d.getGiorno()<<"/"<<d.getMese()<<"/"<<d.getAnno()<<" "<<d.getOre()<<":"<<d.getMinuti()<<":"<<d.getSecondi();
    return os;
}
