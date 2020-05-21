#include "model.h"
#include "appuntamento.h"
#include "eventodurata.h"
#include "promemoria.h"
#include "eventoricorrente.h"
#include "lista.cpp"
#include "impegno.h"
#include "compleanno.h"
#include <iostream>
#include <QFile>
#include <QDebug>
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

bool Model::esporta()
{
    QFile lista("lista.xml");
        if(!lista.open(QIODevice::WriteOnly | QIODevice::Text))
        {
            qDebug()<<"Open the file for writing failed";
            return false;
        }
        else
        {

            QXmlStreamWriter stream;
            stream.setDevice(&lista);
            stream.setAutoFormatting(true);
            stream.writeStartDocument();
            stream.writeStartElement("Evento");
            for(Lista<Evento*>::const_iterator cit=l.begin(); cit!=l.end();++cit){
                (*cit)->toExp(stream);
                stream.writeCharacters("\n");
            }
            stream.writeEndElement();
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
        if (reader.readNextStartElement()){
            if(reader.name()=="Evento"){
                while(reader.readNextStartElement()){
                    if(reader.name()=="Promemoria"){
                        e=(new Promemoria)->fromImp(reader);
                    }
                    else{
                        if(reader.name()=="Appuntamento"){
                            e=(new Appuntamento)->fromImp(reader);
                        }
                        else{
                            if(reader.name()=="Impegno"){
                                e=(new Impegno)->fromImp(reader);
                            }
                            else{
                                if(reader.name()=="Compleanno"){                                    
                                    e=(new Compleanno)->fromImp(reader);
                                }
                                else
                                    reader.skipCurrentElement();
                            }
                        }
                    }
                insert(e);
            }

            lista.close();
            return true;
            }
            else{
                reader.raiseError(QObject::tr("Incorrect file"));
                return false;
            }
        }
        else return false;
    }
}

vector<Lista<Evento*>::const_iterator> Model::getSelezionati() const{
    return selezionati;
}

Lista<Evento *> Model::Getl() const{
    return l;
}
