#include "impegno.h"

Impegno::Impegno() : Evento() {}

Impegno::Impegno(std::string s, Dataora di, Dataora df, vector<Data> v, Color c)
    : Evento(s,di,c), EventoDurata(s,di,df,c), EventoRicorrente(s,di,v,c) {}

Impegno::Impegno(std::string s, Dataora di, Dataora df, ModeRicorrenza mode, int interval, int nRic, Color c) : Evento(s,di,c), EventoDurata(s,di,df,c){
    Data d=getDataInizio();
    switch (mode) { //creazione automatica delle ricorrenze, in base al tipo di intervallo
    case 0: //giorni
        for(int i=0;i<nRic;i++){
            d.avanzaGiorni(interval);
            addRicorrenza(d);
        }
        break;
    case 1: //settimane
        for(int i=0;i<nRic;i++){
            d.avanzaGiorni(interval*7);
            addRicorrenza(d);
        }
        break;
    case 2: //mesi
        for(int i=0;i<nRic;i++){
            d.avanzaMesi(interval);
            addRicorrenza(d);
        }
        break;
    default:
        //some kind of error
        break;
    }
}

std::string Impegno::descrizioneMin() const{
    std::stringstream text;
    text<<getDataInizio().getOrario()<<"-"<<getDataFine().getOrario()<<" Durata: ";
    int ore = int(Dataora::secondsToHours(durata()));
    if(durata()%3600==0){ //ora intera
        text<<ore<<" ora/e\n";
    }else{  //ora non intera
        text<<ore<<" ora/e e "<<int(Dataora::secondsToMinutes(durata()-ore*3600))<<" minuti\n";
    }
    text<<getTitolo();
    return text.str();
}

std::string Impegno::descrizioneFull() const{
    std::stringstream text;
    text<<"<Impegno>\n <Titolo>"<<getTitolo()<<"</Titolo>\n <DataInizio>"<<getDataInizio().getGiorno()<<","<<getDataInizio().getMese()<<","<<getDataInizio().getAnno()<<",";
    text<<getDataInizio().getOre()<<","<<getDataInizio().getMinuti()<<","<<getDataInizio().getSecondi()<<"</DataInizio>\n <DataFine>";
    text<<getDataFine().getGiorno()<<","<<getDataFine().getMese()<<","<<getDataFine().getAnno()<<",";
    text<<getDataFine().getOre()<<","<<getDataFine().getMinuti()<<","<<getDataFine().getSecondi()<<"</DataFine>\n <Colore>"<<getColore()<<"</Colore>\n <Ricorrenze>";
    for(Data d : *getRicorrenze()) { //scorro il vettore delle date ricorrenti
        text<<"|"<<d.getGiorno()<<","<<d.getMese()<<","<<d.getAnno();
    }
    text<<"</Ricorrenze>\n </Impegno>";
    return text.str();
}

void Impegno::toExp(QXmlStreamWriter & stream)
{
    stream.writeStartElement("Impegno");
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
    stream.writeTextElement("Colore",QString::fromStdString(std::to_string(getColore())));
    stream.writeStartElement("Ricorrenze");
    for(Data d : *getRicorrenze()) { //scorro il vettore delle date ricorrenti
        stream.writeStartElement("Ricor");
        stream.writeTextElement("Giorno",QString::fromStdString(std::to_string(d.getGiorno())));
        stream.writeTextElement("Mese",QString::fromStdString(std::to_string(d.getMese())));
        stream.writeTextElement("Anno",QString::fromStdString(std::to_string(d.getAnno())));
        stream.writeEndElement();
    }
    stream.writeEndElement();
    stream.writeEndElement();
}

Evento *Impegno::fromImp(QXmlStreamReader &stream)
{
    string tit;
    Dataora in,fi;
    int col;
    vector<Data> v;
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
                    if(stream.name()=="Colore")
                        col=stoi(stream.readElementText().toStdString());
                    else{
                        if(stream.name()=="Ricorrenze"){
                            while(stream.readNextStartElement()){
                                if(stream.name()=="Ricor"){
                                    v.push_back(Data(sToData(stream)));
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return new Impegno (tit,in,fi,v,(Color)col);
}

bool Impegno::operator==(const Evento & e) const{
    const Impegno* i = dynamic_cast<const Impegno*>(&e);
    if(i){
        return EventoRicorrente::operator==(e) && EventoDurata::operator==(e);
    }else{
        return false;
    }
}

bool Impegno::operator!=(const Evento & e) const{
    return !(*this==e);
}

Impegno *Impegno::clone() const{
    return new Impegno(*this);
}

Color Impegno::colorePred = blue;
