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
                        stringtoData(dat,g,m,a,o,mp,s);
                    }
                        break;
                    case 2:{
                        desc=reader.readElementText().toStdString();
                    }
                        break;
                    case 3:{
                        col=reader.readElementText().toStdString();
                    }
                        break;
                    }
                }
                e=new Promemoria(tit,Dataora(g,m,a,o,mp,s),desc);

            }
            else{
                if(reader.name()=="Appuntamento"){//new Appuntamento("Ex",Dataora(13,5,2020,10,10,10),Dataora(13,5,2020,12,10,10),"Ufficio");
                    string tit,luogo,col;
                    unsigned int g,m,a,o,mp,s;//dataora inizio
                    unsigned int g2,m2,a2,o2,mp2,s2;//dataora fine
                    for(int i=0; i<5&&reader.readNextStartElement();++i){
                        switch(i){
                        case 0:{
                            tit=reader.readElementText().toStdString();
                        }
                            break;
                        case 1:{
                            string dat=(reader.readElementText()).toStdString();
                            stringtoData(dat,g,m,a,o,mp,s);
                        }
                            break;
                        case 2:{
                            string dat=(reader.readElementText()).toStdString();
                            stringtoData(dat,g2,m2,a2,o2,mp2,s2);
                        }
                            break;
                        case 3:{
                            luogo=reader.readElementText().toStdString();
                        }
                            break;
                        case 4:{
                            col=reader.readElementText().toStdString();
                        }
                            break;
                        }
                    }
                    e=new Appuntamento(tit,Dataora(g,m,a,o,mp,s),Dataora(g2,m2,a2,o2,mp2,s2),luogo);

                }
                else{
                    if(reader.name()=="Impegno"){//new Impegno("conferenza",Dataora(11,5,2020,11,11,11),Dataora(11,5,2020,12,12,12),giorno,2,3);
                        string tit,luogo,col;
                        unsigned int g,m,a,o,mp,s;//dataora inizio
                        unsigned int g2,m2,a2,o2,mp2,s2;//dataora fine
                        for(int i=0; i<4&&reader.readNextStartElement();++i){
                            switch(i){
                            case 0:{
                                tit=reader.readElementText().toStdString();
                            }
                                break;
                            case 1:{
                                string dat=(reader.readElementText()).toStdString();
                                stringtoData(dat,g,m,a,o,mp,s);
                            }
                                break;
                            case 2:{
                                string dat=(reader.readElementText()).toStdString();
                                stringtoData(dat,g2,m2,a2,o2,mp2,s2);
                            }
                                break;
                            case 3:{
                                col=reader.readElementText().toStdString();
                            }
                                break;
                            }
                        }
                        //e=new Impegno(tit,Dataora(g,m,a,o,mp,s),Dataora(g2,m2,a2,o2,mp2,s2),luogo);

                    }
                    else{//compleanno new Compleanno("Michele Baldisseri",Dataora(16,5,2020,00,00,00),Data(16,5,1999));
                        string tit,col;
                        unsigned int g,m,a,o,mp,s;//dataora inizio
                        unsigned int g2,m2,a2;//data compleanno
                        for(int i=0; i<4&&reader.readNextStartElement();++i){
                            switch(i){
                            case 0:{
                                tit=reader.readElementText().toStdString();
                            }
                                break;
                            case 1:{
                                string dat=(reader.readElementText()).toStdString();
                                stringtoData(dat,g,m,a,o,mp,s);
                            }
                                break;
                            case 2:{
                                string dat=(reader.readElementText()).toStdString();
                                //stringtoData(dat,g2,m2,a2);
                            }
                                break;
                            case 3:{
                                col=reader.readElementText().toStdString();
                            }
                                break;
                            }
                        }
                        e=new Compleanno(tit,Dataora(g,m,a,o,mp,s),Data(g2,m2,a2));


                    }
                }
            }
        insert(e);
    }
        lista.close();
        return true;
    }
}

void Model::stringtoData(string dat, unsigned int &g, unsigned int &m, unsigned int &a, unsigned int &o, unsigned int &mp, unsigned int &s)
{
    int prova=0;
    int lim=dat.find(",", prova);
    g=stoi(dat.substr(prova, lim));

    prova=lim+1;
    lim=dat.find(",", prova);
    m=stoi(dat.substr(prova, lim));
    prova=lim+1;
    lim=dat.find(",", prova);
    a=stoi(dat.substr(prova, lim));
    prova=lim+1;
    lim=dat.find(",", prova);
    o=stoi(dat.substr(prova, lim));
    prova=lim+1;
    lim=dat.find(",", prova);
    mp=stoi(dat.substr(prova, lim));
    prova=lim+1;
    lim=dat.find("\n", prova);
    s=stoi(dat.substr(prova, lim));
}

vector<Lista<Evento*>::const_iterator> Model::getSelezionati() const{
    return selezionati;
}

Lista<Evento *> Model::Getl() const{
    return l;
}
