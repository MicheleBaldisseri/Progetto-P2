#include "eventoricorrente.h"

EventoRicorrente::EventoRicorrente() : Evento(){}

EventoRicorrente::EventoRicorrente(std::string s, dataora di, vector<dataora> v, Color c)
    : Evento(s,di,c), ricorrenze(v){}

void EventoRicorrente::addRicorrenza(const dataora& d){
    ricorrenze.push_back(d);     //controllare condivisione di memoria!
}

vector<dataora>* EventoRicorrente::getRicorrenze() const{
    return new vector<dataora>(ricorrenze);
}

bool EventoRicorrente::operator==(const Evento & e) const{
    const EventoRicorrente* er = dynamic_cast<const EventoRicorrente*>(&e);
    if(er){
        return Evento::operator==(e) && ricorrenze==*(er->getRicorrenze());
    }else{
        return false;
    }
}

bool EventoRicorrente::operator!=(const Evento & e) const{
    return !(*this==e);
}
