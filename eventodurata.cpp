#include "eventodurata.h"

EventoDurata::EventoDurata() : Evento(), dataFine(){}

EventoDurata::EventoDurata(std::string s, dataora di, dataora df, Color c)
    : Evento(s,di,c), dataFine(df){}

dataora EventoDurata::getDataFine() const{
    return dataFine;
}

int EventoDurata::durata() const{
    //return (dataFine-dataInizio).secToHour();
    return 1;
}

bool EventoDurata::operator==(const Evento & e) const{
    const EventoDurata* ed = dynamic_cast<const EventoDurata*>(&e);
    if(ed){
        return Evento::operator==(e) && ed->getDataFine()==dataFine;
    }else{
        return false;
    }
}

bool EventoDurata::operator!=(const Evento & e) const{
    return !(*this==e);
}

bool EventoDurata::operator>(const Evento & e) const{
    const EventoDurata* ed = dynamic_cast<const EventoDurata*>(&e);
    if(ed){
        return Evento::operator>(e) && dataFine>ed->getDataFine();
    }else{
        return Evento::operator>(e);
    }
}

bool EventoDurata::operator<(const Evento & e) const{
    const EventoDurata* ed = dynamic_cast<const EventoDurata*>(&e);
    if(ed){
        return Evento::operator<(e) && dataFine<ed->getDataFine();
    }else{
        return Evento::operator<(e);
    }
}
