#include "compleanno.h"

Compleanno::Compleanno() : EventoRicorrente(), dataNascita(){}

Compleanno::Compleanno(std::string s, Dataora di, vector<Data> v, Data dn, Color c)
    : Evento(s,di,c), EventoRicorrente(s,di,v,c), dataNascita(dn){}

std::string Compleanno::descrizioneMin() const{
    std::stringstream text;
    text<<"Compleanno di "<<getTitolo()<<"\nEta': "<<((getDataInizio().getAnno())-(getDataNascita().getAnno()));
    return text.str();
}

std::string Compleanno::descrizioneFull() const{
    std::stringstream text;
    text<<"Compleanno"<<"|"<<getTitolo()<<"|"<<getDataInizio().getGiorno()<<"|"<<getDataInizio().getMese()<<"|"<<getDataInizio().getAnno()<<"|";
    text<<getDataInizio().getOre()<<"|"<<getDataInizio().getMinuti()<<"|"<<getDataInizio().getSecondi()<<"|";
    text<<getDataNascita().getGiorno()<<"|"<<getDataNascita().getMese()<<"|"<<getDataNascita().getAnno()<<"|"<<getColore();
    for(Data d : *getRicorrenze()) { //scorro il vettore delle date ricorrenti
        text<<"|"<<d.getGiorno()<<"|"<<d.getMese()<<"|"<<d.getAnno();
    }
    return text.str();
}

Data Compleanno::getDataNascita() const{
    return dataNascita;
}

bool Compleanno::operator==(const Evento & e) const{
    const Compleanno* c = dynamic_cast<const Compleanno*>(&e);
    if(c){
        return EventoRicorrente::operator==(e) && dataNascita==c->getDataNascita();
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

Color Compleanno::colorePred = red;
