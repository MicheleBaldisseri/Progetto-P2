#include "appuntamento.h"


Appuntamento::Appuntamento() : EventoDurata(), luogo(""){}

Appuntamento::Appuntamento(std::string s, dataora di, dataora df, std::string l, Color c)
    : Evento (s,di,c), EventoDurata(s,di,df,c), luogo(l){}

std::string Appuntamento::descrizioneMin() const{
    std::stringstream text;
    text<<getDataInizio().getOrario()<<" - "<<getDataFine().getOrario()<<"\n"<<getTitolo()<<"\nLuogo: "<<getLuogo();
    return text.str();
}

std::string Appuntamento::descrizioneFull() const{
    std::stringstream text;
    text<<"Appuntamento"<<"|"<<getTitolo()<<"|"<<getDataInizio().getGiorno()<<"|"<<getDataInizio().getMese()<<"|"<<getDataInizio().getAnno()<<"|";
    text<<getDataInizio().getOre()<<"|"<<getDataInizio().getMinuti()<<"|"<<getDataInizio().getSecondi()<<"|";
    text<<getDataFine().getGiorno()<<"|"<<getDataFine().getMese()<<"|"<<getDataFine().getAnno()<<"|";
    text<<getDataFine().getOre()<<"|"<<getDataFine().getMinuti()<<"|"<<getDataFine().getSecondi()<<"|"<<getLuogo()<<"|"<<getColore();
    return text.str();
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
