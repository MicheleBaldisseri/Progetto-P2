#include <iostream>
#include "dataora.h"
using namespace std;
template <class T> class lista;
template <class T> ostream& operator<<(ostream&, const lista<T>&);

template <class T=Evento>
class lista{
	//friend class constiterator;
	friend ostream& operator<< <T>(ostream&, const lista<T>&);
private:
	class nodo{
	public:
		T info;
		dataora data;
		nodo* next;
		nodo(const T& t=T(),nodo* n=0): info(t), next(n){}
		~nodo(){delete next;} //ricorsivamente richiama il distruttore di nodo su tutta la lista
	};
	nodo* first, *last;
	static bool isBefore(nodo* a, nodo* b){
		if(!a) return true;
		if(!b) return false;
		return a->data < b->data;
	}
	static nodo* copy(nodo* a, nodo*& b){
		if(!a) return 0;
		if(!a->next){
			b=a;
			return a;
		}
		else return new nodo(a->info, copy(a->next,b));
	}
public:
	//lista(const T& t) costruisce una lista contenente l’elemento t
	lista(const T& t=T()): first(0), last(0){insert(t);}
	//costruttore copia profonda
	lista(const lista& c): first(copy(c.first, last)){}
	//overload assegnazione
	lista& operator=(const lista& c){
		if(this != &c){
			delete first;
			first=copy(c.first, last);
		}
		return *this;
	}
	//distruttore
	~lista(){delete first; delete last;}
	//Deve essere disponibile un metodo void insert(const T&) con il seguente comportamento: c.insert(t) inserisce
	//l’elemento t in lista a c in tempo costante.
	void insert(const T& t){
		nodo* nuovo;
		if(!first){
			nuovo=new nodo(t);
			last=first=nuovo;
		}
		else{
			nuovo=new nodo(t,first->next);
			first=nuovo;
		}
	}
