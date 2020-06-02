#include "promemoria.h"

Promemoria::Promemoria():Evento(), desc() {}

Promemoria::Promemoria(const string& tit, const Dataora& di, const string& d, const Color& c) : Evento(tit,di,c), desc(d) {

    std::size_t pos = 0;
    while ((pos = desc.find('|',pos)) != std::string::npos) {
         desc.replace(pos, 1, " ");
    }
}

std::string Promemoria::descrizioneMin() const{
    std::stringstream text;
    text<< std::setw(2) << std::setfill('0') << getDataInizio().getOre() <<":"<< std::setw(2) << std::setfill('0') << getDataInizio().getMinuti()<<"\n"<<getTitolo()<<" - "<<desc;
    return text.str();
}

std::string Promemoria::descrizioneFull() const{
    std::stringstream text;
    text<<"Promemoria"<<"|"<<getTitolo()<<"|"<<getDataInizio().getGiorno()<<"|"<<getDataInizio().getMese()<<"|"<<getDataInizio().getAnno()<<"|";
    text<<getDataInizio().getOre()<<"|"<<getDataInizio().getMinuti()<<"|"<<getDataInizio().getSecondi()<<"|"<<getColore()<<"|";
    text<<getDesc();
    return text.str();
}

void Promemoria::setDesc(const string & d)
{
    desc=d;
    std::size_t pos = 0;
    while ((pos = desc.find('|',pos)) != std::string::npos) {
         desc.replace(pos, 1, " ");
    }
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

Color Promemoria::colorePred = red;
