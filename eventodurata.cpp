#include "eventodurata.h"

EventoDurata::EventoDurata() : Evento(), dataFine(){}

EventoDurata::EventoDurata(const string& tit, const Dataora& di, const Dataora& df, const Color& c) : Evento(tit,di,c), dataFine(df){
    if(dataFine<di){
        dataFine=di;
    }
}

void EventoDurata::setDataFine(const Dataora & df)
{
    if(dataFine<getDataInizio()){
        dataFine=getDataInizio();
    }else dataFine=df;
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
