#include <iostream>

template <class T>
class lista{
private:
	class nodo{
	public:
		T info;
		nodo* next;
		nodo(const T& t=T(),nodo* n=0): info(t), next(n){}
		~nodo(){delete next;}
	};
	nodo* first, *last;
public:
	static nodo* copy(nodo* a, nodo*& b){
		if(!a) return 0;
		if(!a->next){
			b=a;
			return a;
		}
		else return new nodo(a->info, copy(a->next,b));
	}
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

		void insert(const T& t){
		nodo* nuovo;
		if(!first){
			nuovo=new nodo(t);
			last=first=nuovo;
		}
		else{
			nuovo=new nodo(t);
			if(nuovo<first){
				nodo* inizio=nuovo;//caso in cui l'evento è il primo nella lista
				nuovo->next=first;
				first=nuovo;
			}
			if(last<nuovo){
				nuovo->next=last->next;//caso in cui l'evento è l'ultimo nella lista
				last->next=nuovo;
				last=nuovo;
			}
			nodo* prec=first;
			for(const_iterator cit=cit.begin()->next; cit!=cit.end(); ++cit){
				if(nuovo<cit){
					prec->next=nuovo;
					nuovo->next=cit;
				}
				prec=prec->next;
			}
		}
	}
	nodo& operator[](const unsigned int i) const {
		unsigned int j=0;
		const_iterator cit=cit.begin();
		while(j<i||cit!=cit.end()){
			++j;
			++cit;
		}
		if(j==i) return *cit;
		else{
			std::cout<<"error: out of bound"<<std::endl;
			return *((cit.end())->next);
		}
	}
	class const_iterator{
		public:
			nodo* punt;
			//operator++ prefisso
			const_iterator& operator++() {
				if (punt)
					punt = punt->next;
				return *this;
			}

			const_iterator operator++(int) {
				const_iterator aux = *this;
				if (punt)
					punt = punt->next;
				return aux;
			}
			bool operator==(const const_iterator& x) const {
			  return punt==x.punt;
			}

			bool operator!=(const const_iterator& x) const {
			  return punt!=x.punt;
			}
			const T& operator*() const {
			  return punt->info;
			}
		const_iterator begin() const {
			const_iterator aux;
			aux.punt = first;
			return aux;
		}

		const_iterator end() const {
			const_iterator aux;
			aux.punt = last;
			return aux;
		}
	};
};
