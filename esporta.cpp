#include "esporta.h"

#include "esporta.h"
#include "evento.h"

Esporta::Esporta(Lista<Evento *> &eventi):lista("lista.xml"),l(eventi){}

bool Esporta::Export()
{
    if(!lista.open(QIODevice::WriteOnly | QIODevice::Text))
        return false;

    else
    {
        QXmlStreamWriter stream;
        stream.setDevice(&lista);
        stream.setAutoFormatting(true);
        stream.writeStartDocument();
        stream.writeStartElement("Evento");
        for(Lista<Evento*>::const_iterator cit=l.begin(); cit!=l.end();++cit){
             Appuntamento*a=dynamic_cast<Appuntamento*>(*cit);
             if(a)
                 appToXML(stream,a);
             else{
                 Impegno*i=dynamic_cast<Impegno*>(*cit);
                 if(i)
                     impToXML(stream,i);
                 else{
                     Promemoria*p=dynamic_cast<Promemoria*>(*cit);
                     if(p)
                         promToXML(stream,p);
                     else{
                        Compleanno*c=dynamic_cast<Compleanno*>(*cit);
                        compToXML(stream,c);
                     }
                 }
             }
        }
        stream.writeEndElement();
        stream.writeEndDocument();
        lista.close();
        return true;
    }

}
void Esporta::appToXML(QXmlStreamWriter &stream,Appuntamento *a){
    stream.writeStartElement("Appuntamento");
    stream.writeTextElement("Titolo",QString::fromStdString(a->getTitolo()));
    stream.writeStartElement("DataInizio");
    stream.writeTextElement("Giorno",QString::fromStdString(std::to_string(a->getDataInizio().getGiorno())));
    stream.writeTextElement("Mese",QString::fromStdString(std::to_string(a->getDataInizio().getMese())));
    stream.writeTextElement("Anno",QString::fromStdString(std::to_string(a->getDataInizio().getAnno())));
    stream.writeTextElement("Ora",QString::fromStdString(std::to_string(a->getDataInizio().getOre())));
    stream.writeTextElement("Minuti",QString::fromStdString(std::to_string(a->getDataInizio().getMinuti())));
    stream.writeTextElement("Secondi",QString::fromStdString(std::to_string(a->getDataInizio().getSecondi())));
    stream.writeEndElement();
    stream.writeStartElement("DataFine");
    stream.writeTextElement("Giorno",QString::fromStdString(std::to_string(a->getDataFine().getGiorno())));
    stream.writeTextElement("Mese",QString::fromStdString(std::to_string(a->getDataFine().getMese())));
    stream.writeTextElement("Anno",QString::fromStdString(std::to_string(a->getDataFine().getAnno())));
    stream.writeTextElement("Ora",QString::fromStdString(std::to_string(a->getDataFine().getOre())));
    stream.writeTextElement("Minuti",QString::fromStdString(std::to_string(a->getDataFine().getMinuti())));
    stream.writeTextElement("Secondi",QString::fromStdString(std::to_string(a->getDataFine().getSecondi())));
    stream.writeEndElement();
    stream.writeTextElement("Luogo",QString::fromStdString(a->getLuogo()));
    stream.writeTextElement("Colore",QString::fromStdString(std::to_string(a->getColore())));
    stream.writeEndElement();
}

void Esporta::promToXML(QXmlStreamWriter &stream, Promemoria *p){
    stream.writeStartElement("Promemoria");
    stream.writeTextElement("Titolo",QString::fromStdString(p->getTitolo()));
    stream.writeStartElement("DataInizio");
    stream.writeTextElement("Giorno",QString::fromStdString(std::to_string(p->getDataInizio().getGiorno())));
    stream.writeTextElement("Mese",QString::fromStdString(std::to_string(p->getDataInizio().getMese())));
    stream.writeTextElement("Anno",QString::fromStdString(std::to_string(p->getDataInizio().getAnno())));
    stream.writeTextElement("Ora",QString::fromStdString(std::to_string(p->getDataInizio().getOre())));
    stream.writeTextElement("Minuti",QString::fromStdString(std::to_string(p->getDataInizio().getMinuti())));
    stream.writeTextElement("Secondi",QString::fromStdString(std::to_string(p->getDataInizio().getSecondi())));
    stream.writeEndElement();
    stream.writeTextElement("Desc",QString::fromStdString(p->getDesc()));
    stream.writeTextElement("Colore",QString::fromStdString(std::to_string(p->getColore())));
    stream.writeEndElement();
}

void Esporta::impToXML(QXmlStreamWriter &stream, Impegno *i){
    stream.writeStartElement("Impegno");
    stream.writeTextElement("Titolo",QString::fromStdString(i->getTitolo()));
    stream.writeStartElement("DataInizio");
    stream.writeTextElement("Giorno",QString::fromStdString(std::to_string(i->getDataInizio().getGiorno())));
    stream.writeTextElement("Mese",QString::fromStdString(std::to_string(i->getDataInizio().getMese())));
    stream.writeTextElement("Anno",QString::fromStdString(std::to_string(i->getDataInizio().getAnno())));
    stream.writeTextElement("Ora",QString::fromStdString(std::to_string(i->getDataInizio().getOre())));
    stream.writeTextElement("Minuti",QString::fromStdString(std::to_string(i->getDataInizio().getMinuti())));
    stream.writeTextElement("Secondi",QString::fromStdString(std::to_string(i->getDataInizio().getSecondi())));
    stream.writeEndElement();
    stream.writeStartElement("DataFine");
    stream.writeTextElement("Giorno",QString::fromStdString(std::to_string(i->getDataFine().getGiorno())));
    stream.writeTextElement("Mese",QString::fromStdString(std::to_string(i->getDataFine().getMese())));
    stream.writeTextElement("Anno",QString::fromStdString(std::to_string(i->getDataFine().getAnno())));
    stream.writeTextElement("Ora",QString::fromStdString(std::to_string(i->getDataFine().getOre())));
    stream.writeTextElement("Minuti",QString::fromStdString(std::to_string(i->getDataFine().getMinuti())));
    stream.writeTextElement("Secondi",QString::fromStdString(std::to_string(i->getDataFine().getSecondi())));
    stream.writeEndElement();
    stream.writeTextElement("Colore",QString::fromStdString(std::to_string(i->getColore())));
    stream.writeStartElement("Ricorrenze");
    for(Data d : *(i->getRicorrenze())) { //scorro il vettore delle date ricorrenti
        stream.writeStartElement("Ricor");
        stream.writeTextElement("Giorno",QString::fromStdString(std::to_string(d.getGiorno())));
        stream.writeTextElement("Mese",QString::fromStdString(std::to_string(d.getMese())));
        stream.writeTextElement("Anno",QString::fromStdString(std::to_string(d.getAnno())));
        stream.writeEndElement();
    }
    stream.writeEndElement();
    stream.writeEndElement();
}

void Esporta::compToXML(QXmlStreamWriter &stream, Compleanno *c){
    stream.writeStartElement("Compleanno");
    stream.writeTextElement("Titolo",QString::fromStdString(c->getTitolo()));
    stream.writeStartElement("DataInizio");
    stream.writeTextElement("Giorno",QString::fromStdString(std::to_string(c->getDataInizio().getGiorno())));
    stream.writeTextElement("Mese",QString::fromStdString(std::to_string(c->getDataInizio().getMese())));
    stream.writeTextElement("Anno",QString::fromStdString(std::to_string(c->getDataInizio().getAnno())));
    stream.writeTextElement("Ora",QString::fromStdString(std::to_string(c->getDataInizio().getOre())));
    stream.writeTextElement("Minuti",QString::fromStdString(std::to_string(c->getDataInizio().getMinuti())));
    stream.writeTextElement("Secondi",QString::fromStdString(std::to_string(c->getDataInizio().getSecondi())));
    stream.writeEndElement();
    stream.writeStartElement("DataNascita");
    stream.writeTextElement("Giorno",QString::fromStdString(std::to_string(c->getDataNascita().getGiorno())));
    stream.writeTextElement("Mese",QString::fromStdString(std::to_string(c->getDataNascita().getMese())));
    stream.writeTextElement("Anno",QString::fromStdString(std::to_string(c->getDataNascita().getAnno())));
    stream.writeEndElement();
    stream.writeTextElement("Colore",QString::fromStdString(std::to_string(c->getColore())));
    stream.writeEndElement();
}
