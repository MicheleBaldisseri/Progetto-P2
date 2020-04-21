#include "orario.h"

Orario::Orario(int o, int m, int s){
    if(o<0 || o>23 || m<0 || m>59 || s<0 || s>59) sec=0;
    else sec= o*3600+ m*60+ s;
}

Orario::Orario(unsigned int s):sec(s){}

Orario::Orario(const Orario & o):sec(o.sec){}

Orario &Orario::operator=(const Orario &o){
    if(this!=&o)
        sec=o.sec;
    return *this;
}

Orario::~Orario(){}

int Orario::getOre() const
{
    return sec/3600;
}

int Orario::getMinuti() const
{
    return (sec/60) %60;
}

int Orario::getSecondi() const
{
    return sec%60;
}

void Orario::setOre(int o)
{
    sec=o*3600+getMinuti()*60+getSecondi();
}

void Orario::setMinuti(int m)
{
    sec=getOre()*3600+m*60+getSecondi();
}

void Orario::setSecondi(int s)
{
    sec=getOre()*3600+getMinuti()*60+s;
}

void Orario::avanzaOre(int o){
    sec=(sec+3600*o)%86400;
}

std::string Orario::getOrario() const{
    return std::to_string(getOre())+":"+std::to_string(getMinuti())+":"+std::to_string(getSecondi());
}


Orario Orario::operator-(const Orario &o) const
{

    Orario aux;
    int secondi=sec-o.sec;

    if(secondi<0)
        secondi=86400-(secondi*(-1));

    aux.sec=secondi%86400;
    return aux;

}

bool Orario::operator==(const Orario &o) const
{
    return sec==o.sec;
}

bool Orario::operator!=(const Orario &o) const
{
    return sec!=o.sec;
}

bool Orario::operator<(const Orario &o) const
{
    if(sec<o.sec) return true;
    else return false;
}

bool Orario::operator>(const Orario &o) const
{
    if(sec>o.sec) return true;
    else return false;
}

unsigned int Orario::getCampoDati() const
{
    return sec;
}


ostream& operator<<(ostream& os, const Orario& o) {
    return os<<o.getOre()<<":"<<o.getMinuti()<<":"<<o.getSecondi();
}

