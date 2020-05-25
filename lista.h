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
        ~nodo(){if(next!=0)delete next;}
    };
    nodo* last, *first;
public:
    static Lista<T>::nodo* copy(nodo* a, nodo*& b);
    Lista();

        //costruttore copia profonda
        Lista(const Lista& c);
        //overload assegnazione
        Lista& operator=(const Lista& c);
        //distruttore
        ~Lista();
        void push_front(const T& t);
        void push_back(const T& t);
        T& operator[](int i) const;
        class const_iterator{
            friend class Lista<T>;
            private:
                nodo* punt;
            public:
                //operator++ prefisso
                const_iterator(nodo*n=nullptr):punt(n){}
                const_iterator& operator++();
                const_iterator operator++(int);
                const_iterator& operator--();
                const_iterator operator--(int);
                bool operator==(const const_iterator& x) const;
                bool operator!=(const const_iterator& x) const;
                const T& operator*() const;
        };
        const_iterator erase(const_iterator&);
        const_iterator begin() const;
        const_iterator end() const;
    };

#include "lista.cpp"

#endif // LISTA_H
