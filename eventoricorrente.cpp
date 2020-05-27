#include "eventoricorrente.h"

EventoRicorrente::EventoRicorrente() : Evento(){}

EventoRicorrente::EventoRicorrente(const string& tit, const Dataora& di, const vector<Data>& ric, const Color& c)
    : Evento(tit,di,c), ricorrenze(ric){}

void EventoRicorrente::addRicorrenza(const Data& d){
    ricorrenze.push_back(d);
}

vector<Data> EventoRicorrente::getRicorrenze() const{
    return ricorrenze;
}

bool EventoRicorrente::operator==(const Evento & e) const{
    const EventoRicorrente* er = dynamic_cast<const EventoRicorrente*>(&e);
    if(er){
        return Evento::operator==(e) && ricorrenze==(er->getRicorrenze());
    }else{
        return false;
    }
}

bool EventoRicorrente::operator!=(const Evento & e) const{
    return !(*this==e);
}
