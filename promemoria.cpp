#include "promemoria.h"

Promemoria::Promemoria():Evento(), desc() {}

Promemoria::Promemoria(std::string s, Dataora di, std::string d, Color c)
    : Evento(s,di,c), desc(d) {}

std::string Promemoria::descrizioneMin() const{
    std::stringstream text;
    text<< std::setw(2) << std::setfill('0') << getDataInizio().getOre() <<":"<< std::setw(2) << std::setfill('0') << getDataInizio().getMinuti()<<"\n"<<getTitolo()<<" - "<<desc;
    return text.str();
}

std::string Promemoria::descrizioneFull() const{
    std::stringstream text;
    text<<"<Promemoria>\n <Titolo>"<<getTitolo()<<"</Titolo>\n <DataInizio>"<<getDataInizio().getGiorno()<<","<<getDataInizio().getMese()<<","<<getDataInizio().getAnno()<<",";
    text<<getDataInizio().getOre()<<","<<getDataInizio().getMinuti()<<","<<getDataInizio().getSecondi()<<"</DataInizio>\n <Desc>";
    text<<getDesc()<<"</Desc>\n <Colore>"<<getColore()<<"</Colore>\n </Promemoria>";
    return text.str();
}

std::string Promemoria::getDesc() const{
    return desc;
}

void Promemoria::toExp(QXmlStreamWriter & stream)
{
    stream.writeStartElement("Promemoria");
    stream.writeTextElement("Titolo",QString::fromStdString(getTitolo()));
    stream.writeStartElement("DataInizio");
    stream.writeTextElement("Giorno",QString::fromStdString(std::to_string(getDataInizio().getGiorno())));
    stream.writeTextElement("Mese",QString::fromStdString(std::to_string(getDataInizio().getMese())));
    stream.writeTextElement("Anno",QString::fromStdString(std::to_string(getDataInizio().getAnno())));
    stream.writeTextElement("Ora",QString::fromStdString(std::to_string(getDataInizio().getOre())));
    stream.writeTextElement("Minuti",QString::fromStdString(std::to_string(getDataInizio().getMinuti())));
    stream.writeTextElement("Secondi",QString::fromStdString(std::to_string(getDataInizio().getSecondi())));
    stream.writeEndElement();
    stream.writeTextElement("Desc",QString::fromStdString(getDesc()));
    stream.writeTextElement("Colore",QString::fromStdString(std::to_string(getColore())));
    stream.writeEndElement();
}

Evento *Promemoria::fromImp(QXmlStreamReader &stream)
{
    string tit,desc;
    Dataora dat;
    int col;
    while(stream.readNextStartElement()){
        if(stream.name()=="Titolo")
            tit=stream.readElementText().toStdString();
        else{
            if(stream.name()=="DataInizio")
                dat=sToDataOra(stream);
            else{
                if(stream.name()=="Desc")
                    desc=stream.readElementText().toStdString();
                else{
                    if(stream.name()=="Colore")
                        col=stoi(stream.readElementText().toStdString());
                }
            }
        }
    }
    return new Promemoria(tit,dat,desc,(Color)col);
}

bool Promemoria::operator==(const Evento & e) const{
    const Promemoria* p = dynamic_cast<const Promemoria*>(&e);
    if(p){
        return Evento::operator==(e) && desc==p->getDesc();
    }else{
        return false;
    }
}

bool Promemoria::operator!=(const Evento & e) const{
    return !(*this==e);
}

Promemoria *Promemoria::clone() const{
    return new Promemoria(*this);
}

Color Promemoria::colorePred = red;
