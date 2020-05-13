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
#include <QFile>
#include <QTextStream>



bool Model::modify(Lista<Evento*>::const_iterator it, Evento *nuovo)
{

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

void Model::showEvent(const Data & d)
{
    selezionati.clear();
    for(Lista<Evento*>::const_iterator cit=l.begin();cit!=l.end();++cit){
        EventoRicorrente*r=dynamic_cast<EventoRicorrente*>(*cit);
        if(!r){//se evento è di tipo EventoDurata o Promemoria
            if(d==(*cit)->getDataInizio()){
                selezionati.push_back(cit);
            }
        }
        else{//se evento è di tipo EventoRicorrente
            vector<Data>* v=r->getRicorrenze();
            for(vector<Data>::const_iterator c=v->begin();c!=v->end();++c){
                if(*c==d)
                    selezionati.push_back(cit);
            }
        }
    }
    if(selezionati.size()==0){
        throw new std::invalid_argument("Nessun evento presente nella data specificata");
    }
}

bool Model::esporta()//inserire una lettera per identificare tipo
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
/*Evento* create(string& s){
    string nuova;
    if(s[0]=='A'){
        //Evento* eA = new Appuntamento("Ex",Dataora(20,10,2010,10,10,10),Dataora(20,10,2010,12,10,10),"Ufficio");
        nuova="new Appuntamento(\"";
        unsigned int cont=0;
        for(unsigned int i=0; s[i]!='\n'; ++i){
            if(s[i]=='|') ++cont;
            if(cont>1&&s[i]!='|')
                nuova=nuova+s[i];
            if(cont==2&&s[i]=='|')
                nuova=nuova+"\",Dataora(";
            if(cont>2&&cont<8&&s[i]=='|')
                nuova=nuova+",";
            if(cont==8&&s[i]=='|')
                nuova=nuova+"),Dataora(";
            if(cont>8&&cont<14&&s[i]=='|')
                nuova=nuova+",";
            if(cont==14&&s[i]=='|')
                nuova=nuova+"),\"";
            if(cont==15&&s[i]=='|')
                nuova=nuova+"\",";
        }
        nuova=nuova+");";
        cout<<"stringa "<<nuova<<endl;
        Evento *e=nuova;
        return e;
    }
}*/
bool Model::importa()
{
    /*QFile lista("lista.txt");
    int cont=0;
    if (!lista.open(QIODevice::ReadOnly | QIODevice::Text))
            return false;
    QTextStream t(&lista);
        while (!t.atEnd()) {
            QString s = t.readLine();
            cout << s.toStdString()<<endl;
            Evento*e=create(s.toStdString());
            if(!insert(e))
                ++cont;
        }
        if(cont!=0)cout<<cont<<" eventi non inseriti perché già presenti"<<endl;*/
        return true;
}
