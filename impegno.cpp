#include "impegno.h"

Impegno::Impegno() : Evento() {}

Impegno::Impegno(std::string s, Dataora di, Dataora df, vector<Data> v, Color c)
    : Evento(s,di,c), EventoDurata(s,di,df,c), EventoRicorrente(s,di,v,c) {}

Impegno::Impegno(std::string s, Dataora di, Dataora df, ModeRicorrenza mode, int interval, int nRic, Color c) : Evento(s,di,c), EventoDurata(s,di,df,c){
    Data d=getDataInizio();
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
    default:
        //some kind of error
        break;
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
    text<<"<Impegno>\n <Titolo>"<<getTitolo()<<"</Titolo>\n <DataInizio>"<<getDataInizio().getGiorno()<<","<<getDataInizio().getMese()<<","<<getDataInizio().getAnno()<<",";
    text<<getDataInizio().getOre()<<","<<getDataInizio().getMinuti()<<","<<getDataInizio().getSecondi()<<"</DataInizio>\n <DataFine>";
    text<<getDataFine().getGiorno()<<","<<getDataFine().getMese()<<","<<getDataFine().getAnno()<<",";
    text<<getDataFine().getOre()<<","<<getDataFine().getMinuti()<<","<<getDataFine().getSecondi()<<"</DataFine>\n <Colore>"<<getColore()<<"</Colore>\n <Ricorrenze>";
    for(Data d : *getRicorrenze()) { //scorro il vettore delle date ricorrenti
        text<<"|"<<d.getGiorno()<<","<<d.getMese()<<","<<d.getAnno();
    }
    text<<"</Ricorrenze>\n </Impegno>";
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
