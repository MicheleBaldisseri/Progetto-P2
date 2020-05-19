#include "promemoria.h"

Promemoria::Promemoria():Evento(), desc() {}

Promemoria::Promemoria(std::string s, Dataora di, std::string d, Color c)
    : Evento(s,di,c), desc(d) {}

std::string Promemoria::descrizioneMin() const{
    std::stringstream text;
    text<<getDataInizio().getOrario()<<"\n"<<getTitolo()<<" - "<<desc;
    return text.str();
}

std::string Promemoria::descrizioneFull() const{
    std::stringstream text;
    text<<"<Promemoria>\n <Titolo>"<<getTitolo()<<"</Titolo>\n <DataInizio>("<<getDataInizio().getGiorno()<<","<<getDataInizio().getMese()<<","<<getDataInizio().getAnno()<<",";
    text<<getDataInizio().getOre()<<","<<getDataInizio().getMinuti()<<","<<getDataInizio().getSecondi()<<")</DataInizio>\n <Desc>";
    text<<getDesc()<<"</Desc>\n <Colore>"<<getColore()<<"</Colore>\n </Promemoria>";
    return text.str();
}

std::string Promemoria::getDesc() const{
    return desc;
}

bool Promemoria::operator==(const Evento & e) const{
    const Promemoria* p = dynamic_cast<const Promemoria*>(&e);
    if(p){
        return Evento::operator==(e) && desc==p->getDesc();
    }else{
        return false;
    }
}

bool Promemoria::operator!=(const Evento & e) const{
    return !(*this==e);
}

Promemoria *Promemoria::clone() const{
    return new Promemoria(*this);
}

Color Promemoria::colorePred = yellow;
