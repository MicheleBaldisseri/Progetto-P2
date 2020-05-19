#include "appuntamento.h"


Appuntamento::Appuntamento() : EventoDurata(), luogo(""){}

Appuntamento::Appuntamento(std::string s, Dataora di, Dataora df, std::string l, Color c)
    : Evento (s,di,c), EventoDurata(s,di,df,c), luogo(l){}

std::string Appuntamento::descrizioneMin() const{
    std::stringstream text;
    text<<getDataInizio().getOrario()<<"-"<<getDataFine().getOrario()<<" Durata: ";
    int ore = int(Dataora::secondsToHours(durata()));
    if(durata()%3600==0){ //ora intera
        text<<ore<<" ora/e\n";
    }else{  //ora non intera
        text<<ore<<" ora/e e "<<int(Dataora::secondsToMinutes(durata()-ore*3600))<<" minuti\n";
    }
    text<<getTitolo()<<"\nLuogo: "<<getLuogo();
    return text.str();
}

std::string Appuntamento::descrizioneFull() const{
    std::stringstream text;
    text<<"<Appuntamento>\n <Titolo>"<<getTitolo()<<"</Titolo>\n <DataInizio>("<<getDataInizio().getGiorno()<<","<<getDataInizio().getMese()<<","<<getDataInizio().getAnno()<<",";
    text<<getDataInizio().getOre()<<","<<getDataInizio().getMinuti()<<","<<getDataInizio().getSecondi()<<")</DataInizio>\n <DataFine>(";
    text<<getDataFine().getGiorno()<<","<<getDataFine().getMese()<<","<<getDataFine().getAnno()<<",";
    text<<getDataFine().getOre()<<","<<getDataFine().getMinuti()<<","<<getDataFine().getSecondi()<<")</DataFine>\n <Luogo>"<<getLuogo()<<"</Luogo>\n <Colore>"<<getColore()<<"</Colore>\n </Appuntamento>";
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
