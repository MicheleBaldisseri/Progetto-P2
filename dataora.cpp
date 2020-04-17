#include "dataora.h"


dataora::dataora():data(),orario(){}

dataora::dataora(int gg, int mm, int aa, int o, int m, int s):data(gg,mm,aa),orario(o,m,s){}

dataora::dataora(const dataora &d):data(d.getGiorno(),d.getMese(),d.getAnno()), orario(d.getOre(),d.getMinuti(),d.getSecondi()){}

unsigned int dataora::operator-(const dataora &d) const
{
    dataora aux(d), obj(*this);
    unsigned int sec=0;
    if(obj > aux){
        unsigned int gg=0;
        if(d.getSecondi()<getSecondi())
            while(d.getSecondi()==getSecondi())
                sec++;
        //se l'orario è dopo ad obj arrivo fino a mezzanotte
        if(d.getSecondi()>getSecondi()){
            while(d.getSecondi()==86400)
                sec++;
            //sono arrivato a mezzanotte quindi passo al giorno successivo
            aux.avanzaGiorni(1);
        }
        while(aux != obj){
            gg++;
            aux.avanzaGiorni(1);
        }
        sec += gg*86400;
    }
    return sec;
}

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

std::ostream &operator<<(std::ostream &os, const dataora &d)
{
    std::cout<<d.getGiorno()<<"/"<<d.getMese()<<"/"<<d.getAnno()<<" "<<d.getOre()<<":"<<d.getMinuti()<<":"<<d.getSecondi()<<std::endl;
    return os;
}
