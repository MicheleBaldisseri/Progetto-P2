#include "eventodurata.h"

EventoDurata::EventoDurata() : Evento(), dataFine(){}

EventoDurata::EventoDurata(std::string s, Dataora di, Dataora df, Color c) : Evento(s,di,c), dataFine(df){
    if(dataFine<di){
        dataFine=di;
    }
}

Dataora EventoDurata::getDataFine() const{
    return dataFine;
}

int EventoDurata::durata() const{
    return dataFine-getDataInizio();
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
        if(getDataInizio()==e.getDataInizio())return dataFine>ed->getDataFine();
        else return Evento::operator >(e);
    }else{
        return Evento::operator>(e);
    }
}

bool EventoDurata::operator<(const Evento & e) const{
    const EventoDurata* ed = dynamic_cast<const EventoDurata*>(&e);
    if(ed){
        if(getDataInizio()==e.getDataInizio())return dataFine<ed->getDataFine();
        else return Evento::operator <(e);
    }else{
        return Evento::operator<(e);
    }
}
