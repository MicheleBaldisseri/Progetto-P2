#include "compleanno.h"

Compleanno::Compleanno() : EventoRicorrente(), persona(""), dataNascita(){}

Compleanno::Compleanno(std::string s, dataora di, vector<dataora> v, string p, data dn, Color c)
    : EventoRicorrente(s,di,v,c), persona(p), dataNascita(dn){}

std::string Compleanno::descrizione() const{
    return "Compleanno";
}

std::string Compleanno::getPersona() const{
    return persona;
}

data Compleanno::getDataNascita() const{
    return dataNascita;
}

bool Compleanno::operator==(const Evento & e) const{
    const Compleanno* c = dynamic_cast<const Compleanno*>(&e);
    if(c){
        return EventoRicorrente::operator==(e) && persona==c->getPersona() && dataNascita==c->getDataNascita();
    }else{
        return false;
    }
}

bool Compleanno::operator!=(const Evento & e) const{
    return !(*this==e);
}

Compleanno *Compleanno::clone() const{
    return new Compleanno(*this);
}
