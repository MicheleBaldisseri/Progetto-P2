#include "impegno.h"

Impegno::Impegno(){

}

Impegno::Impegno(std::string s, Dataora di, Dataora df, vector<Data> v, Color c)
    : Evento(s,di,c), EventoDurata(s,di,df,c), EventoRicorrente(s,di,v,c){}

std::string Impegno::descrizioneMin() const{
    std::stringstream text;
    text<<getDataInizio().getOrario()<<"-"<<getDataFine().getOrario()<<" Durata: "<<durata()<<" Ora/e\n"<<getTitolo();
    return text.str();
}

std::string Impegno::descrizioneFull() const{
    std::stringstream text;
    text<<"Impegno"<<"|"<<getTitolo()<<"|"<<getDataInizio().getGiorno()<<"|"<<getDataInizio().getMese()<<"|"<<getDataInizio().getAnno()<<"|";
    text<<getDataInizio().getOre()<<"|"<<getDataInizio().getMinuti()<<"|"<<getDataInizio().getSecondi()<<"|";
    text<<getDataFine().getGiorno()<<"|"<<getDataFine().getMese()<<"|"<<getDataFine().getAnno()<<"|";
    text<<getDataFine().getOre()<<"|"<<getDataFine().getMinuti()<<"|"<<getDataFine().getSecondi()<<"|"<<getColore();
    for(Data d : *getRicorrenze()) { //scorro il vettore delle date ricorrenti
        text<<"|"<<d.getGiorno()<<"|"<<d.getMese()<<"|"<<d.getAnno();
    }
    return text.str();
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
