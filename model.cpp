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
#include <QXmlStreamReader>
#include <QXmlStreamWriter>
#include <QFile>
#include <QDebug>
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
            if(**cit==*e){
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
            if(d==(*cit)->getDataInizio()){
                selezionati.push_back(cit);
            }
            vector<Data>* v=r->getRicorrenze();
            for(vector<Data>::const_iterator c=v->begin();c!=v->end();++c){
                if(*c==d)
                    selezionati.push_back(cit);
            }
        }
    }
}

bool Model::esporta()//inserire una lettera per identificare tipo
{
    QFile lista("lista.xml");
        if(!lista.open(QIODevice::WriteOnly | QIODevice::Text))
        {
            qDebug()<<"Open the file for writing failed";
            return false;
        }
        else
        {
            QXmlStreamWriter stream(&lista);
            stream.setAutoFormatting(true);
            //stream.writeStartDocument();
            for(Lista<Evento*>::const_iterator cit=l.begin(); cit!=l.end();++cit){

                stringstream p;
                p<<**cit;
                stream.writeEntityReference(QString::fromStdString(p.str()));
                stream.writeCharacters("\n");
            }
            stream.writeEndDocument();
            lista.close();
            qDebug()<<"Writing is done";
            return true;
        }

}
void stringtoData(string& dat, unsigned int& g,unsigned int& m,unsigned int& a,unsigned int& o,unsigned int& mp,unsigned int& s){
    g=stoi(dat.substr(0, dat.find(",", 0)));
    m=stoi(dat.substr(0, dat.find(",", 0)));
    a=stoi(dat.substr(0, dat.find(",", 0)));
    o=stoi(dat.substr(0, dat.find(",", 0)));
    mp=stoi(dat.substr(0, dat.find(",", 0)));
    s=stoi(dat.substr(0, dat.find("\n", 0)));
}
bool Model::importa()
{
    QFile lista("lista.xml");
    if(!lista.open(QIODevice::ReadOnly | QIODevice::Text)){
        qDebug()<<"Open the file for reading failed";
        return false;
    }
    else{
        QXmlStreamReader reader(&lista);
        Evento*e;
        while(reader.readNextStartElement()){
            qDebug()<<reader.name();
            if(reader.name()=="Promemoria"){//new Promemoria("Denti",Dataora(14,5,2020,5,11,47),"Lavati i denti");
                string tit,desc,col;
                unsigned int g,m,a,o,mp,s;
                for(int i=0; i<4&&reader.readNextStartElement();++i){
                    switch(i){
                    case 0:{
                        tit=reader.readElementText().toStdString();
                    }
                        break;
                    case 1:{
                        string dat=(reader.readElementText()).toStdString();
                        //stringtoData(dat,g,m,a,o,mp,s);
                        g=stoi(dat.substr(0, dat.find(",", 0)));
                        m=stoi(dat.substr(0, dat.find(",", 0)));
                        a=stoi(dat.substr(0, dat.find(",", 0)));
                        o=stoi(dat.substr(0, dat.find(",", 0)));
                        mp=stoi(dat.substr(0, dat.find(",", 0)));
                        s=stoi(dat.substr(0, dat.find("\n", 0)));
                    }
                        break;
                    case 2:{
                        desc=reader.readElementText().toStdString();
                    }
                        break;
                    case 3:{
                        col=reader.readElementText().toStdString();
                    }
                    }
                }
                e=new Promemoria(tit,Dataora(g,m,a,o,mp,s),desc);
                insert(e);
            }
            else{
                if(reader.name()=="Appuntamento"){
                    reader.readNextStartElement();
                    reader.readNextStartElement();
                    reader.readNextStartElement();
                    reader.readNextStartElement();
                    reader.readNextStartElement();
                    //reader.readNextStartElement();
                }
                else{
                    if(reader.name()=="Impegno"){
                        reader.readNextStartElement();
                    }
                    else{//compleanno
                        reader.readNextStartElement();
                    }
                }
            }
        insert(e);
    }
        lista.close();
        return true;
    }
}

vector<Lista<Evento*>::const_iterator> Model::getSelezionati() const{
    return selezionati;
}

Lista<Evento *> Model::Getl() const{
    return l;
}
