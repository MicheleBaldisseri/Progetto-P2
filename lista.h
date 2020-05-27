
#ifndef LISTA_H
#define LISTA_H
#include <iostream>


using namespace std;
template <class T>
class Lista{
private:
    class nodo{
    public:
        T info;
        nodo* next;
        nodo(const T& t=T(),nodo* n=nullptr): info(t), next(n){}
        ~nodo(){if(next!=0)delete next;}//distruttore invocato anche per il nodo next
    };
    nodo *last,*first;//puntano rispettivamente all'ultimo e al primo nodo
public:
    static Lista<T>::nodo* copy(nodo* a, nodo*& b);//copia nodo a in nodo b
    Lista();

        //costruttore copia profonda
        Lista(const Lista& c);
        //overload assegnazione
        Lista& operator=(const Lista& c);
        //distruttore
        ~Lista();
        void push_front(const T& t);//inserisce nodo all'inizio
        void push_back(const T& t);//inserisce nodo alla fine
        class const_iterator{//classe iteratore costante amica della classe lista
            friend class Lista<T>;
            private:
                nodo* punt;
            public:
                const_iterator(nodo*n=nullptr):punt(n){}
                //overloading operatori
                const_iterator& operator++();//operator++ prefisso
                const_iterator operator++(int);//operator++ postfisso
                const_iterator& operator--();//operator-- prefisso
                const_iterator operator--(int);//operator-- postfisso
                bool operator==(const const_iterator& x) const;
                bool operator!=(const const_iterator& x) const;
                const T& operator*() const;
        };
        const_iterator erase(const_iterator&);//cancella elemento della lista
        const_iterator begin() const;//ritorna const_iterator che punta a first
        const_iterator end() const;//ritorna const_iterator che punta a last
    };


#include "lista.cpp"
#endif // LISTA_H
