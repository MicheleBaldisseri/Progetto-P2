#include "lista.h"

template<class T>
typename Lista<T>::nodo* Lista<T>::copy(Lista<T>::nodo *a, Lista<T>::nodo *&b){
    if(!a) return 0;
    if(!a->next){
        b= new nodo(a->info, nullptr);
        return b;
    }
    else{
        return new nodo(a->info, copy(a->next,b));
    }
}

template<class T>
Lista<T>::Lista():last(nullptr),first(nullptr){}

template<class T>
Lista<T>::Lista(const Lista &c): first(copy(c.first, last)){}

template<class T>
Lista<T> &Lista<T>::operator=(const Lista<T> &c){
    if(this != &c){
        delete first;
        first=copy(c.first, last);
    }
    return *this;
}

template<class T>
Lista<T>::~Lista(){delete first;}

template<class T>
void Lista<T>::push_front(const T &t)
{
    Lista<T>::nodo* nuovo=new nodo(t);
    if(!first){
        last=nuovo;
        first=nuovo;
    }
    else{
        nuovo->next=first;
        first=nuovo;
    }
}

template<class T>
void Lista<T>::push_back(const T &t)
{
    Lista<T>::nodo* nuovo=new nodo(t);
    if(!first){
        last=nuovo;
        first=nuovo;
    }
    else{
        last->next=nuovo;
        last=nuovo;
    }
}

template<class T>
T& Lista<T>::operator[](int i) const { //se non esiste, throw overflow error
    int j=0;
    Lista<T>::const_iterator cit=begin();
    bool out=false;

    while(j!=i && !out){
        if(cit==end())
            out=true;
        else{
            ++j;
            ++cit;
        }
    }
    if(j==i) {
        return cit.punt->info;
    }
    else{
        throw new std::overflow_error("Out of Bounds");
    }
}

template<class T>
typename Lista<T>::const_iterator &Lista<T>::const_iterator::operator++() {
    if (punt)
        punt = punt->next;
    return *this;
}

template<class T>
typename Lista<T>::const_iterator Lista<T>::const_iterator::operator++(int) {
    const_iterator aux = *this;
    if (punt)
        punt = punt->next;
    return aux;
}

template<class T>
bool Lista<T>::const_iterator::operator==(const Lista<T>::const_iterator &x) const {
    return punt==x.punt;
}

template<class T>
bool Lista<T>::const_iterator::operator!=(const Lista<T>::const_iterator &x) const {
    return punt!=x.punt;
}

template<class T>
const T &Lista<T>::const_iterator::operator*() const {
    return punt->info;
}

template<class T>
typename Lista<T>::const_iterator Lista<T>::erase(Lista<T>::const_iterator& canc) //se iteratore non presente, undefined behavior
{
    nodo* succ;
    if(canc==begin()){ //nodo da cancellare e' il primo
        first=first->next;
        canc.punt->next=nullptr;
        delete canc.punt;

        if(first==nullptr)last=nullptr; //lista vuota

        return first;
    }
    else{   //nodo da cancellare e' in mezzo
        Lista<T>::const_iterator prec=begin();
        Lista<T>::const_iterator cit=begin();
        cit++;
        for(;cit!=canc;cit++){
            prec++;
        }

        succ=canc.punt->next;
        prec.punt->next=succ;

        if(last==canc.punt)last=prec.punt; //cancellato ultimo elemento, last si sposta indietro

        canc.punt->next=nullptr;
        delete canc.punt;

        return succ;
    }
}

template<class T>
typename Lista<T>::const_iterator Lista<T>::begin() const
{
    return first;
}

template<class T>
typename Lista<T>::const_iterator Lista<T>::end() const
{
    return nullptr;
}
