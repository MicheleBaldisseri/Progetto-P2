#include "appuntamento.h"


Appuntamento::Appuntamento() : EventoDurata(), luogo(""){}

Appuntamento::Appuntamento(std::string s, dataora di, dataora df, std::string l, Color c)
    : EventoDurata(s,di,df,c), luogo(l){}

std::string Appuntamento::descrizione() const{
    return "Appuntamento";
}

std::string Appuntamento::getLuogo() const{
    return luogo;
}

bool Appuntamento::operator==(const Evento & e) const{
    const Appuntamento* a = dynamic_cast<const Appuntamento*>(&e);
    if(a){
        return EventoDurata::operator==(e) && luogo==a->getLuogo();
    }else{
        return false;
    }
}

bool Appuntamento::operator!=(const Evento& e) const{
    return !(*this==e);
}

Appuntamento *Appuntamento::clone() const{
    return new Appuntamento(*this);
}

Color Appuntamento::colorePred = green;
