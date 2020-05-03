#include "lista.h"

template<class T>
typename Lista<T>::nodo* Lista<T>::copy(Lista<T>::nodo *a, Lista<T>::nodo *&b){
    if(!a) return 0;
    if(!a->next){
        b=a;
        return a;
    }
    else return new nodo(a->info, copy(a->next,b));
}

template<class T>
Lista<T>::Lista():first(0),last(0){}

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
Lista<T>::~Lista(){delete first; delete last;}

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
T& Lista<T>::operator[](int i) const {
    int j=0;
    Lista<T>::const_iterator cit=begin();
    bool out=false;

    while(j!=i && !out){
        if(cit==end())
            out==true;
        else{
            ++j;
            ++cit;
        }
    }
    if(j==i) {
        return cit.punt->info;
    }
    else{
        std::cout<<"error: out of bound"<<std::endl;
        return last->info;
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
typename Lista<T>::const_iterator Lista<T>::erase(Lista<T>::const_iterator& canc)
{
    Lista<T>::const_iterator aux;
    if(canc==begin()){
        aux=++canc;
        first=aux.punt;
        (*canc.punt).next=nullptr;
        //delete canc.punt;
        return aux;
    }
    else{
        Lista<T>::const_iterator prec=begin();
        for(const_iterator cit=++prec;cit!=canc;++cit){
            ++prec;
        }

        if(canc==end()){
            aux.punt=nullptr;
            (*(prec.punt)).next=nullptr;
            last=prec.punt;
        }
        else{
            aux=(*canc.punt).next;
            (*(prec.punt)).next=aux.punt;
            (*canc.punt).next=nullptr;
        }
        delete canc.punt;
        return aux;
    }
}

template<class T>
typename Lista<T>::const_iterator Lista<T>::begin() const
{
    Lista<T>::const_iterator aux;
    aux.punt=this->first;
    return aux;
}

template<class T>
typename Lista<T>::const_iterator Lista<T>::end() const
{
    Lista<T>::const_iterator aux;
    aux.punt=(*this).last;
    return aux;
}
