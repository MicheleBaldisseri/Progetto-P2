#include "evento.h"
#include <iostream>
using std::string;

Evento::Evento() : titolo(""), dataInizio(), colore(white){}

Evento::Evento(string s, Dataora di, Color c)
    : titolo(s), dataInizio(di), colore(c){}

void Evento::setColore(const Color& c){
    colore=c;
}

Color Evento::getColore() const{
    return colore;
}

std::string Evento::getTitolo() const{
    return titolo;
}

Dataora Evento::getDataInizio() const{
    return dataInizio;
}

bool Evento::operator==(const Evento & e) const{
    return e.getTitolo()==titolo && e.getColore()==colore && e.getDataInizio()==dataInizio;
}

bool Evento::operator!=(const Evento & e) const{
    return !(*this==e);
}

bool Evento::operator>(const Evento & e) const{
    return dataInizio>e.getDataInizio();
}

bool Evento::operator<(const Evento & e) const{
    return dataInizio<e.getDataInizio();
}

Dataora Evento::sToDataOra(QXmlStreamReader &stream)
{
    int g,m,a,o,mp,s;
    while(stream.readNextStartElement()){
        if(stream.name()=="Giorno")
            g=stoi(stream.readElementText().toStdString());
        else{
            if(stream.name()=="Mese")
                m=stoi(stream.readElementText().toStdString());
            else{
                if(stream.name()=="Anno")
                    a=stoi(stream.readElementText().toStdString());
                else{
                    if(stream.name()=="Ora")
                        o=stoi(stream.readElementText().toStdString());
                    else{
                        if(stream.name()=="Minuti")
                            mp=stoi(stream.readElementText().toStdString());
                        else
                            s=stoi(stream.readElementText().toStdString());
                    }
                }
            }
        }
    }
    Dataora d(g,m,a,o,mp,s);
    return d;
}

Data Evento::sToData(QXmlStreamReader &stream)
{
    int g,m,a;
    while(stream.readNextStartElement()){
        if(stream.name()=="Giorno")
            g=stoi(stream.readElementText().toStdString());
        else{
            if(stream.name()=="Mese")
                m=stoi(stream.readElementText().toStdString());
            else{
                if(stream.name()=="Anno")
                    a=stoi(stream.readElementText().toStdString());
            }
        }
    }
    Data d(g,m,a);
    return d;
}

std::ostream &operator<<(std::ostream & os, const Evento & e){
    //richiama la stampa polimorfa di tutti i campi dati
    return os<<e.descrizioneFull();
}
