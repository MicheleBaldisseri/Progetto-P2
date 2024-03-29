#include "compleanno.h"

Compleanno::Compleanno() : EventoRicorrente(), dataNascita(){}

Compleanno::Compleanno(const string& nome, const Dataora& di, const Data& dn, const int& limit, const Color& c) : Evento(nome,di,c), dataNascita(dn){
    Data d=getDataInizio();
    for(int i=0;i<limit;i++){//creazione delle ricorrenze
        d.avanzaAnni(1);
        addRicorrenza(d);
    }
}

std::string Compleanno::descrizioneMin() const{
    std::stringstream text;
    text<<"Compleanno di "<<getTitolo()<<"\nEta': "<<((getDataInizio().getAnno())-(getDataNascita().getAnno()))<< " anni";
    return text.str();
}

std::string Compleanno::descrizioneFull() const{
    std::stringstream text;
    text<<"Compleanno"<<"|"<<getTitolo()<<"|"<<getDataInizio().getGiorno()<<"|"<<getDataInizio().getMese()<<"|"<<getDataInizio().getAnno()<<"|";
    text<<getDataInizio().getOre()<<"|"<<getDataInizio().getMinuti()<<"|"<<getDataInizio().getSecondi()<<"|"<<getColore()<<"|";
    text<<getDataNascita().getGiorno()<<"|"<<getDataNascita().getMese()<<"|"<<getDataNascita().getAnno();
    for(Data d : getRicorrenze()) { //scorro il vettore delle date ricorrenti
        text<<"|"<<d.getGiorno()<<"|"<<d.getMese()<<"|"<<d.getAnno();
    }
    return text.str();
}

void Compleanno::setDataNascita(const Data & dn)
{
    dataNascita=dn;
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

Color Compleanno::colorePred = orange;
