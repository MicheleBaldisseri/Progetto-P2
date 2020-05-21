#include "appuntamento.h"


Appuntamento::Appuntamento() : EventoDurata(), luogo(""){}

Appuntamento::Appuntamento(std::string s, Dataora di, Dataora df, std::string l, Color c)
    : Evento (s,di,c), EventoDurata(s,di,df,c), luogo(l){}

std::string Appuntamento::descrizioneMin() const{
    std::stringstream text;
    text<< std::setw(2) << std::setfill('0') << getDataInizio().getOre() <<":"<< std::setw(2) << std::setfill('0') << getDataInizio().getMinuti() <<" - ";
    text<< std::setw(2) << std::setfill('0') << getDataFine().getOre() <<":"<< std::setw(2) << std::setfill('0') << getDataFine().getMinuti();
    text<<"\n"<<getTitolo()<<" - Luogo: "<<getLuogo();
    text<<"\nDurata: ";
    int ore = int(Dataora::secondsToHours(durata()));
    if(durata()%3600==0){ //ora intera
        text<<ore<<" ora/e";
    }else{  //ora non intera
        text<<ore<<" ora/e e "<<int(Dataora::secondsToMinutes(durata()-ore*3600))<<" minuti";
    }
    return text.str();
}

std::string Appuntamento::descrizioneFull() const{
    std::stringstream text;
    text<<"<Appuntamento>\n <Titolo>"<<getTitolo()<<"</Titolo>\n <DataInizio>"<<getDataInizio().getGiorno()<<","<<getDataInizio().getMese()<<","<<getDataInizio().getAnno()<<",";
    text<<getDataInizio().getOre()<<","<<getDataInizio().getMinuti()<<","<<getDataInizio().getSecondi()<<"</DataInizio>\n <DataFine>";
    text<<getDataFine().getGiorno()<<","<<getDataFine().getMese()<<","<<getDataFine().getAnno()<<",";
    text<<getDataFine().getOre()<<","<<getDataFine().getMinuti()<<","<<getDataFine().getSecondi()<<"</DataFine>\n <Luogo>"<<getLuogo()<<"</Luogo>\n <Colore>"<<getColore()<<"</Colore>\n </Appuntamento>";
    return text.str();
}

std::string Appuntamento::getLuogo() const{
    return luogo;
}

void Appuntamento::toExp(QXmlStreamWriter& stream)
{
    stream.writeStartElement("Appuntamento");
    stream.writeTextElement("Titolo",QString::fromStdString(getTitolo()));
    stream.writeStartElement("DataInizio");
    stream.writeTextElement("Giorno",QString::fromStdString(std::to_string(getDataInizio().getGiorno())));
    stream.writeTextElement("Mese",QString::fromStdString(std::to_string(getDataInizio().getMese())));
    stream.writeTextElement("Anno",QString::fromStdString(std::to_string(getDataInizio().getAnno())));
    stream.writeTextElement("Ora",QString::fromStdString(std::to_string(getDataInizio().getOre())));
    stream.writeTextElement("Minuti",QString::fromStdString(std::to_string(getDataInizio().getMinuti())));
    stream.writeTextElement("Secondi",QString::fromStdString(std::to_string(getDataInizio().getSecondi())));
    stream.writeEndElement();
    stream.writeStartElement("DataFine");
    stream.writeTextElement("Giorno",QString::fromStdString(std::to_string(getDataFine().getGiorno())));
    stream.writeTextElement("Mese",QString::fromStdString(std::to_string(getDataFine().getMese())));
    stream.writeTextElement("Anno",QString::fromStdString(std::to_string(getDataFine().getAnno())));
    stream.writeTextElement("Ora",QString::fromStdString(std::to_string(getDataFine().getOre())));
    stream.writeTextElement("Minuti",QString::fromStdString(std::to_string(getDataFine().getMinuti())));
    stream.writeTextElement("Secondi",QString::fromStdString(std::to_string(getDataFine().getSecondi())));
    stream.writeEndElement();
    stream.writeTextElement("Luogo",QString::fromStdString(getLuogo()));
    stream.writeTextElement("Colore",QString::fromStdString(std::to_string(getColore())));
    stream.writeEndElement();
}

Evento *Appuntamento::fromImp(QXmlStreamReader &stream)
{
    string tit,luogo;
    Dataora in,fi;
    int col;
    while(stream.readNextStartElement()){
        if(stream.name()=="Titolo")
            tit=stream.readElementText().toStdString();
        else{
            if(stream.name()=="DataInizio")
                in=sToDataOra(stream);
            else{
                if(stream.name()=="DataFine")
                    fi=sToDataOra(stream);
                else{
                    if(stream.name()=="Luogo")
                        luogo=stream.readElementText().toStdString();
                    else
                        if(stream.name()=="Colore")
                            col=stoi(stream.readElementText().toStdString());
                }
            }
        }
    }
    return new Appuntamento(tit,in,fi,luogo,(Color)col);
}

bool Appuntamento::operator==(const Evento & e) const{
    const Appuntamento* a = dynamic_cast<const Appuntamento*>(&e);
    if(a){
        return EventoDurata::operator==(e) && luogo==a->getLuogo();
    }else{
        return false;
    }
}

bool Appuntamento::operator!=(const Evento& e) const{
    return !(*this==e);
}

Appuntamento *Appuntamento::clone() const{
    return new Appuntamento(*this);
}

Color Appuntamento::colorePred = green;
