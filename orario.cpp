#include "orario.h"

orario::orario(int o, int m, int s){
    if(o<0 || o>23 || m<0 || m>59 || s<0 || s>59) sec=0;
    else sec= o*3600+ m*60+ s;
}

orario::orario(const orario & o):sec(o.sec){}

orario &orario::operator=(const orario &o){
    if(this!=&o)
        sec=o.sec;
    return *this;
}

orario::~orario(){}

int orario::getOre() const{
    return sec/3600;
}

int orario::getMinuti() const{
    return (sec/60) %60;
}

int orario::getSecondi() const{
    return sec%60;
}

void orario::setOre(int o){
    sec=o*3600+getMinuti()*60+getSecondi();
}

void orario::setMinuti(int m){
    sec=getOre()*3600+m*60+getSecondi();
}

void orario::setSecondi(int s){
    sec=getOre()*3600+getMinuti()*60+s;
}

void orario::avanzaOre(int o){
    sec=(sec+3600*o)%86400;
}

ostream& operator<<(ostream& os, const orario& o) {
    return os<<o.getOre()<<":"<<o.getMinuti()<<":"<<o.getSecondi();
}
/*
void orario::AvanzaUnOra(){
    sec=(sec+3600)%86400;
}
orario orario::UnOraPiuTardi() const{
    orario aux(0,0,0);
    aux.sec=(sec+3600)%86400; //NO SIDE EFFECT
    return aux;
}

void orario::StampaSecondi() const{
    cout<<sec<<endl;
}

orario orario::OraDiPranzo(){return orario(13,15);}

//overloading degli operatori
orario orario::operator+(const orario o) const{
    orario aux;
    aux.sec=(sec+o.sec)%86400;
    return aux;
}
orario orario::operator-(orario o) const{
    orario aux;
    aux.sec=(sec-o.sec)%86400;
    return aux;
}
bool orario::operator==(orario o) const{
    if(sec==o.sec) return true;
    else return false;
}
bool orario::operator>(orario o) const{
    if(sec>o.sec) return true;
    else return false;
}
bool orario::operator<(orario o) const{
    if(sec<o.sec) return true;
    else return false;
}

*/
