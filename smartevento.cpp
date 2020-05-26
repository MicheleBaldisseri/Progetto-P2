#include "smartevento.h"

SmartEvento::SmartEvento(Evento *e): ptr(e->clone()){}

SmartEvento::SmartEvento(const SmartEvento &s): ptr(s.ptr->clone()){}

SmartEvento &SmartEvento::operator=(const SmartEvento &s)
{
    if(this != &s) {
        delete ptr;
        ptr=s.ptr->clone();
    }
    return *this;
}

Evento& SmartEvento::operator*() const{return *ptr;}

Evento* SmartEvento::operator->() const{return ptr;}

bool SmartEvento::operator==(const SmartEvento& x) const {
    return *ptr == *(x.ptr);
}

bool SmartEvento::operator>(const SmartEvento& x) const {
    return *ptr > *(x.ptr);
}

bool SmartEvento::operator<(const SmartEvento& x) const {
    return *ptr < *(x.ptr);
}

SmartEvento::~SmartEvento(){delete ptr;}
