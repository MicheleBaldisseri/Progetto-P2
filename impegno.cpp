#include "impegno.h"

Impegno::Impegno(){

}

Impegno::Impegno(std::string s, dataora di, dataora df, vector<dataora> v, Color c)
    : Evento(s,di,c), EventoDurata(s,di,df,c), EventoRicorrente(s,di,v,c){}

std::string Impegno::descrizione() const{
    return "Impegno";
}

bool Impegno::operator==(const Evento & e) const{
    const Impegno* i = dynamic_cast<const Impegno*>(&e);
    if(i){
        return EventoRicorrente::operator==(e) && EventoDurata::operator==(e);
    }else{
        return false;
    }
}

bool Impegno::operator!=(const Evento & e) const{
    return !(*this==e);
}

Impegno *Impegno::clone() const{
    return new Impegno(*this);
}

Color Impegno::colorePred = blue;
