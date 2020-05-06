#include "model.h"
#include "appuntamento.h"
#include "eventodurata.h"
#include "promemoria.h"
#include "eventoricorrente.h"
#include "lista.cpp"
#include "impegno.h"
#include "compleanno.h"
#include <iostream>
#include <fstream>

Model::Model(Lista<Evento*>* e){
    l=*e;
}

bool Model::insert(Evento *e)
{
    if(search(e)==nullptr){
        l.push_back(e);
        return true;
    }
    else return false;
}

Lista<Evento*>::const_iterator Model::search(Evento *e)const
{
    Appuntamento*a=dynamic_cast<Appuntamento*>(e);
    Promemoria*p=dynamic_cast<Promemoria*>(e);
    Lista<Evento*>::const_iterator find;
    if(p||a){//p è di tipo promemoria oppure a è di tipo Appuntamento
        for(Lista<Evento*>::const_iterator cit=l.begin();cit!=l.end()&&find==nullptr; ++cit){
            if(*cit==e){
                find=cit;
            }
        }
    }
    else{
        for(Lista<Evento*>::const_iterator cit=l.begin();cit!=l.end()&&find==nullptr; ++cit){

            if((*cit)->getTitolo()==e->getTitolo()){
                find=cit;
            }
        }
    }
    return find;
}

bool Model::erase(Evento *e)
{
    Lista<Evento*>::const_iterator find=search(e);
    if(find!=nullptr){

        find=l.erase(find);
        return true;
    }
    else{
        throw new std::invalid_argument("Impossibile procedere con l'eliminazione: evento non presente");
        return false;
    }
}

Lista<Evento *> Model::showEvent(const Data & d)
{
    Lista<Evento *> selezionati;
    for(Lista<Evento*>::const_iterator cit=l.begin();cit!=l.end();++cit){
        EventoRicorrente*r=dynamic_cast<EventoRicorrente*>(*cit);
        if(!r){//se evento è di tipo EventoDurata o Promemoria
            if(d==(*cit)->getDataInizio()){
                selezionati.push_back(*cit);
            }
        }
        else{//se evento è di tipo EventoRicorrente
            vector<Data>* v=r->getRicorrenze();
            for(vector<Data>::const_iterator c=v->begin();c!=v->end();++c){
                if(*c==d)
                    selezionati.push_back(r);
            }
        }
    }
    if(selezionati.begin()==nullptr){
        throw new std::invalid_argument("Nessun evento presente nella data specificata");
    }
    return selezionati;
}

bool Model::esporta()
{
    ofstream lista("lista.txt");
    if(lista.is_open()){
        for(Lista<Evento*>::const_iterator cit=l.begin();cit!=l.end();++cit){
            lista<<**cit<<"\n";
        }
        lista.close();
        return lista.good();
    }
    else{
        throw new std::runtime_error("Impossibile aprire il file");
        return false;
    }
}

bool Model::importa()
{
    ifstream lista("lista.txt");
    if(lista.is_open()){
        char* s;
        int n=150;
        char c='\n';
        while(lista.getline(s,n,c)){

            cout<<s<<endl;
        }
        lista.close();
        return true;
    }
    else{
        throw new std::runtime_error("Impossibile aprire il file");
        return false;
    }
}
