#include "compleanno.h"

Compleanno::Compleanno() : EventoRicorrente(), dataNascita(){}

Compleanno::Compleanno(std::string s, Dataora di, Data dn, int limit, Color c) : Evento(s,di,c), dataNascita(dn){
    Data d=getDataInizio();
    for(int i=0;i<limit;i++){//creazione delle ricorrenze
        d.avanzaAnni(1);
        addRicorrenza(d);
    }
}

std::string Compleanno::descrizioneMin() const{
    std::stringstream text;
    text<<"Compleanno di "<<getTitolo()<<"\nEta': "<<((getDataInizio().getAnno())-(getDataNascita().getAnno()));
    return text.str();
}

std::string Compleanno::descrizioneFull() const{
    std::stringstream text;
    text<<"<Compleanno>\n <Titolo>"<<getTitolo()<<"</Titolo>\n <DataInizio>"<<getDataInizio().getGiorno()<<","<<getDataInizio().getMese()<<","<<getDataInizio().getAnno()<<",";
    text<<getDataInizio().getOre()<<","<<getDataInizio().getMinuti()<<","<<getDataInizio().getSecondi()<<"</DataInizio>\n <DataNascita>";
    text<<getDataNascita().getGiorno()<<","<<getDataNascita().getMese()<<","<<getDataNascita().getAnno()<<"</DataNascita>\n <Colore>"<<getColore()<<"</Colore>\n <Ricorrenze>";
    for(Data d : *getRicorrenze()) { //scorro il vettore delle date ricorrenti
        text<<"|"<<d.getGiorno()<<","<<d.getMese()<<","<<d.getAnno();
    }
    text<<"</Ricorrenze>\n</Compleanno>";
    return text.str();
}

void Compleanno::toExp(QXmlStreamWriter &stream)
{
    stream.writeStartElement("Compleanno");
    stream.writeTextElement("Titolo",QString::fromStdString(getTitolo()));
    stream.writeStartElement("DataInizio");
    stream.writeTextElement("Giorno",QString::fromStdString(std::to_string(getDataInizio().getGiorno())));
    stream.writeTextElement("Mese",QString::fromStdString(std::to_string(getDataInizio().getMese())));
    stream.writeTextElement("Anno",QString::fromStdString(std::to_string(getDataInizio().getAnno())));
    stream.writeTextElement("Ora",QString::fromStdString(std::to_string(getDataInizio().getOre())));
    stream.writeTextElement("Minuti",QString::fromStdString(std::to_string(getDataInizio().getMinuti())));
    stream.writeTextElement("Secondi",QString::fromStdString(std::to_string(getDataInizio().getSecondi())));
    stream.writeEndElement();
    stream.writeStartElement("DataNascita");
    stream.writeTextElement("Giorno",QString::fromStdString(std::to_string(getDataNascita().getGiorno())));
    stream.writeTextElement("Mese",QString::fromStdString(std::to_string(getDataNascita().getMese())));
    stream.writeTextElement("Anno",QString::fromStdString(std::to_string(getDataNascita().getAnno())));
    stream.writeEndElement();
    stream.writeTextElement("Colore",QString::fromStdString(std::to_string(getColore())));
    stream.writeEndElement();
}

Evento *Compleanno::fromImp(QXmlStreamReader &stream)
{
    string tit;
    Dataora in;
    Data nas;
    int col;
    while(stream.readNextStartElement()){
        if(stream.name()=="Titolo")
            tit=stream.readElementText().toStdString();
        else{
            if(stream.name()=="DataInizio")
                in=sToDataOra(stream);
            else{
                if(stream.name()=="DataNascita")
                    nas=sToData(stream);
                else{
                    if(stream.name()=="Colore")
                        col=stoi(stream.readElementText().toStdString());
                }
            }
        }
    }
    return new Compleanno(tit,in,nas,20,(Color)col);
}

Data Compleanno::getDataNascita() const{
    return dataNascita;
}

bool Compleanno::operator==(const Evento & e) const{
    const Compleanno* c = dynamic_cast<const Compleanno*>(&e);
    if(c){
        return EventoRicorrente::operator==(e) && dataNascita==c->getDataNascita();
    }else{
        return false;
    }
}

bool Compleanno::operator!=(const Evento & e) const{
    return !(*this==e);
}

Compleanno *Compleanno::clone() const{
    return new Compleanno(*this);
}

Color Compleanno::colorePred = orange;
