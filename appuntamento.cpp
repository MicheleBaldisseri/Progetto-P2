#include "appuntamento.h"


Appuntamento::Appuntamento() : EventoDurata(), luogo(""){}

Appuntamento::Appuntamento(const string& tit, const Dataora& di, const Dataora& df, const string& l, const Color& c) : Evento (tit,di,c), EventoDurata(tit,di,df,c), luogo(l){
    std::size_t pos = 0;
    while ((pos = luogo.find('|',pos)) != std::string::npos) {
         luogo.replace(pos, 1, " ");
    }
}

std::string Appuntamento::descrizioneMin() const{
    std::stringstream text;
    text<< std::setw(2) << std::setfill('0') << getDataInizio().getOre() <<":"<< std::setw(2) << std::setfill('0') << getDataInizio().getMinuti() <<" - ";
    text<< std::setw(2) << std::setfill('0') << getDataFine().getOre() <<":"<< std::setw(2) << std::setfill('0') << getDataFine().getMinuti();
    text<<"\n"<<getTitolo()<<" - Luogo: "<<getLuogo();
    text<<"\nDurata: ";
    int ore = int(Dataora::secondsToHours(durata()));
    if(durata()%3600==0){ //ora intera
        text<<ore<<" ora/e";
    }else{  //ora non intera
        text<<ore<<" ora/e e "<<int(Dataora::secondsToMinutes(durata()-ore*3600))<<" minuti";
    }
    return text.str();
}

std::string Appuntamento::descrizioneFull() const{
    std::stringstream text;
    text<<"Appuntamento"<<"|"<<getTitolo()<<"|"<<getDataInizio().getGiorno()<<"|"<<getDataInizio().getMese()<<"|"<<getDataInizio().getAnno()<<"|";
    text<<getDataInizio().getOre()<<"|"<<getDataInizio().getMinuti()<<"|"<<getDataInizio().getSecondi()<<"|"<<getColore()<<"|";
    text<<getDataFine().getGiorno()<<"|"<<getDataFine().getMese()<<"|"<<getDataFine().getAnno()<<"|";
    text<<getDataFine().getOre()<<"|"<<getDataFine().getMinuti()<<"|"<<getDataFine().getSecondi()<<"|"<<getLuogo();
    return text.str();
}

void Appuntamento::setLuogo(const string & l)
{
    luogo=l;
    std::size_t pos = 0;
    while ((pos = luogo.find('|',pos)) != std::string::npos) {
         luogo.replace(pos, 1, " ");
    }
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
