#include "dataora.h"


Dataora::Dataora():Data(),Orario(){}

Dataora::Dataora(int gg, int mm, int aa, int o, int m, int s):Data(gg,mm,aa),Orario(o,m,s){}

Dataora::Dataora(const Dataora &d):Data(d.getGiorno(),d.getMese(),d.getAnno()), Orario(d.getOre(),d.getMinuti(),d.getSecondi()){}

Dataora::Dataora(const Data &d, const Orario &o):Data(d.getGiorno(),d.getMese(),d.getAnno()), Orario(o.getOre(),o.getMinuti(),o.getSecondi()){}

bool Dataora::operator==(const Dataora &d) const
{
    return Data::operator ==(d) && Orario::operator ==(d);
}

bool Dataora::operator!=(const Dataora &d) const
{
    return Data::operator !=(d) || Orario::operator !=(d);
}

bool Dataora::operator<(const Dataora &d) const
{
    return Data::operator<(d)? true : (Data::operator ==(d)? (Orario::operator <(d)? true : false) : false);
}

bool Dataora::operator>(const Dataora &d) const
{
    return Data::operator >(d)? true : (Data::operator ==(d)? (Orario::operator >(d)? true : false) : false);
}

unsigned int Dataora::operator-(const Dataora &d) const
{
    Data d1(getGiorno(),getMese(),getAnno()),
            d2(d.getGiorno(),d.getMese(),d.getAnno()),
            aux;
    Orario o1(getOre(),getMinuti(),getSecondi()),
            o2(d.getOre(),d.getMinuti(),d.getSecondi());

    bool giornoPrecedente=false;
    int secondi,gg;
    //mi assicuro che il minuendo sia maggiore
    if(d1<d2){
        aux=d1;
        d1=d2;
        d2=aux;
    }
    //faccio la differenza tra i due orari
    secondi=o1.getCampoDati()-o2.getCampoDati();
    //se la diff è negativa significa che sono passato al giorno precedente, ne devo contare uno in meno
    if(secondi<0){
        secondi=86400+secondi;
        giornoPrecedente=true;
    }
    //calcolo la differenza tra i giorni
    gg=d1-d2;
    if(giornoPrecedente) gg--;
    secondi= secondi+ (gg*86400);
    //ritorno tutto in secondi
    return secondi;

}

double Dataora::secondsToHours(unsigned int s)
{
    double sec=s, secInHour=3600;
    return (sec/secInHour);
}

double Dataora::secondsToMinutes(unsigned int s)
{
    double sec=s, secInMinute=60;
    return (sec/secInMinute);
}

std::ostream &operator<<(std::ostream &os, const Dataora &d)
{
    return os<<d.getStringGs(d.getGiornoSettimana())<<" "<<d.getGiorno()<<"/"<<d.getMese()<<"/"<<d.getAnno()<<" "<<d.getOre()<<":"<<d.getMinuti()<<":"<<d.getSecondi();
}
