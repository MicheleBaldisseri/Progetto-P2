#include "impegno.h"

Impegno::Impegno() : Evento() {}

Impegno::Impegno(const string& tit, const Dataora& di, const Dataora& df, const vector<Data>& v, const Color& c)
    : Evento(tit,di,c), EventoDurata(tit,di,df,c), EventoRicorrente(tit,di,v,c) {}

Impegno::Impegno(const string& tit, const Dataora& di, const Dataora& df, const ModeRicorrenza& mode, const int& interval, const int& nRic, const Color& c) : Evento(tit,di,c), EventoDurata(tit,di,df,c){
    Data d=getDataInizio();
    if(interval>=1){
        switch (mode) { //creazione automatica delle ricorrenze, in base al tipo di intervallo
        case 0: //giorni
            for(int i=0;i<nRic;i++){
                d.avanzaGiorni(interval);
                addRicorrenza(d);
            }
            break;
        case 1: //settimane
            for(int i=0;i<nRic;i++){
                d.avanzaGiorni(interval*7);
                addRicorrenza(d);
            }
            break;
        case 2: //mesi
            for(int i=0;i<nRic;i++){
                d.avanzaMesi(interval);
                addRicorrenza(d);
            }
            break;
        default: //non crea le ricorrenze
            break;
        }
    }
}

std::string Impegno::descrizioneMin() const{
    std::stringstream text;
    text<< std::setw(2) << std::setfill('0') << getDataInizio().getOre() <<":"<< std::setw(2) << std::setfill('0') << getDataInizio().getMinuti() <<" - ";
    text<< std::setw(2) << std::setfill('0') << getDataFine().getOre() <<":"<< std::setw(2) << std::setfill('0') << getDataFine().getMinuti();
    text<<"\n"<<getTitolo()<<"\n";
    text<<"Durata: ";
    int ore = int(Dataora::secondsToHours(durata()));
    if(durata()%3600==0){ //ora intera
        text<<ore<<" ora/e";
    }else{  //ora non intera
        text<<ore<<" ora/e e "<<int(Dataora::secondsToMinutes(durata()-ore*3600))<<" minuti";
    }
    return text.str();
}

std::string Impegno::descrizioneFull() const{
    std::stringstream text;
    text<<"Impegno"<<"|"<<getTitolo()<<"|"<<getDataInizio().getGiorno()<<"|"<<getDataInizio().getMese()<<"|"<<getDataInizio().getAnno()<<"|";
    text<<getDataInizio().getOre()<<"|"<<getDataInizio().getMinuti()<<"|"<<getDataInizio().getSecondi()<<"|"<<getColore()<<"|";
    text<<getDataFine().getGiorno()<<"|"<<getDataFine().getMese()<<"|"<<getDataFine().getAnno()<<"|";
    text<<getDataFine().getOre()<<"|"<<getDataFine().getMinuti()<<"|"<<getDataFine().getSecondi();
    for(Data d : getRicorrenze()) { //scorro il vettore delle date ricorrenti
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

Color Impegno::colorePred = purple;
