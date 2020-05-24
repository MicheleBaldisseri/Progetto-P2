#include "esporta.h"

Esporta::Esporta(Lista<SmartEvento> &eventi):lista("lista.xml"),l(eventi){}

bool Esporta::esport()
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
        for(Lista<SmartEvento>::const_iterator cit=l.begin(); cit!=l.end();++cit){
             Appuntamento*a=dynamic_cast<Appuntamento*>((*cit).operator->());
             if(a)
                 appToXML(stream,a);
             else{
                 Impegno*i=dynamic_cast<Impegno*>((*cit).operator->());
                 if(i)
                     impToXML(stream,i);
                 else{
                     Promemoria*p=dynamic_cast<Promemoria*>((*cit).operator->());
                     if(p)
                         promToXML(stream,p);
                     else{
                        Compleanno*c=dynamic_cast<Compleanno*>((*cit).operator->());
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
    stream.writeStartElement("Appuntamento");//apertura tag appuntamento
    stream.writeTextElement("Titolo",QString::fromStdString(a->getTitolo()));//conversione da string a Qstring
    stream.writeStartElement("DataInizio");
    stream.writeTextElement("Giorno",QString::number(a->getDataInizio().getGiorno()));//conversione da int a QString
    stream.writeTextElement("Mese",QString::number(a->getDataInizio().getMese()));
    stream.writeTextElement("Anno",QString::number(a->getDataInizio().getAnno()));
    stream.writeTextElement("Ora",QString::number(a->getDataInizio().getOre()));
    stream.writeTextElement("Minuti",QString::number(a->getDataInizio().getMinuti()));
    stream.writeTextElement("Secondi",QString::number(a->getDataInizio().getSecondi()));
    stream.writeEndElement();
    stream.writeStartElement("DataFine");
    stream.writeTextElement("Giorno",QString::number(a->getDataFine().getGiorno()));
    stream.writeTextElement("Mese",QString::number(a->getDataFine().getMese()));
    stream.writeTextElement("Anno",QString::number(a->getDataFine().getAnno()));
    stream.writeTextElement("Ora",QString::number(a->getDataFine().getOre()));
    stream.writeTextElement("Minuti",QString::number(a->getDataFine().getMinuti()));
    stream.writeTextElement("Secondi",QString::number(a->getDataFine().getSecondi()));
    stream.writeEndElement();
    stream.writeTextElement("Luogo",QString::fromStdString(a->getLuogo()));
    stream.writeTextElement("Colore",QString::number(a->getColore()));
    stream.writeEndElement();//chiusura tag appuntamento
}

void Esporta::promToXML(QXmlStreamWriter &stream, Promemoria *p){
    stream.writeStartElement("Promemoria");
    stream.writeTextElement("Titolo",QString::fromStdString(p->getTitolo()));
    stream.writeStartElement("DataInizio");
    stream.writeTextElement("Giorno",QString::number(p->getDataInizio().getGiorno()));
    stream.writeTextElement("Mese",QString::number(p->getDataInizio().getMese()));
    stream.writeTextElement("Anno",QString::number(p->getDataInizio().getAnno()));
    stream.writeTextElement("Ora",QString::number(p->getDataInizio().getOre()));
    stream.writeTextElement("Minuti",QString::number(p->getDataInizio().getMinuti()));
    stream.writeTextElement("Secondi",QString::number(p->getDataInizio().getSecondi()));
    stream.writeEndElement();
    stream.writeTextElement("Desc",QString::fromStdString(p->getDesc()));
    stream.writeTextElement("Colore",QString::number(p->getColore()));
    stream.writeEndElement();
}

void Esporta::impToXML(QXmlStreamWriter &stream, Impegno *i){
    stream.writeStartElement("Impegno");
    stream.writeTextElement("Titolo",QString::fromStdString(i->getTitolo()));
    stream.writeStartElement("DataInizio");
    stream.writeTextElement("Giorno",QString::number(i->getDataInizio().getGiorno()));
    stream.writeTextElement("Mese",QString::number(i->getDataInizio().getMese()));
    stream.writeTextElement("Anno",QString::number(i->getDataInizio().getAnno()));
    stream.writeTextElement("Ora",QString::number(i->getDataInizio().getOre()));
    stream.writeTextElement("Minuti",QString::number(i->getDataInizio().getMinuti()));
    stream.writeTextElement("Secondi",QString::number(i->getDataInizio().getSecondi()));
    stream.writeEndElement();
    stream.writeStartElement("DataFine");
    stream.writeTextElement("Giorno",QString::number(i->getDataFine().getGiorno()));
    stream.writeTextElement("Mese",QString::number(i->getDataFine().getMese()));
    stream.writeTextElement("Anno",QString::number(i->getDataFine().getAnno()));
    stream.writeTextElement("Ora",QString::number(i->getDataFine().getOre()));
    stream.writeTextElement("Minuti",QString::number(i->getDataFine().getMinuti()));
    stream.writeTextElement("Secondi",QString::number(i->getDataFine().getSecondi()));
    stream.writeEndElement();
    stream.writeTextElement("Colore",QString::number(i->getColore()));
    stream.writeStartElement("Ricorrenze");
    for(Data d : (i->getRicorrenze())) { //scorro il vettore delle date ricorrenti
        stream.writeStartElement("Ricor");
        stream.writeTextElement("Giorno",QString::number(d.getGiorno()));
        stream.writeTextElement("Mese",QString::number(d.getMese()));
        stream.writeTextElement("Anno",QString::number(d.getAnno()));
        stream.writeEndElement();
    }
    stream.writeEndElement();
    stream.writeEndElement();
}

void Esporta::compToXML(QXmlStreamWriter &stream, Compleanno *c){
    stream.writeStartElement("Compleanno");
    stream.writeTextElement("Titolo",QString::fromStdString(c->getTitolo()));
    stream.writeStartElement("DataInizio");
    stream.writeTextElement("Giorno",QString::number(c->getDataInizio().getGiorno()));
    stream.writeTextElement("Mese",QString::number(c->getDataInizio().getMese()));
    stream.writeTextElement("Anno",QString::number(c->getDataInizio().getAnno()));
    stream.writeTextElement("Ora",QString::number(c->getDataInizio().getOre()));
    stream.writeTextElement("Minuti",QString::number(c->getDataInizio().getMinuti()));
    stream.writeTextElement("Secondi",QString::number(c->getDataInizio().getSecondi()));
    stream.writeEndElement();
    stream.writeStartElement("DataNascita");
    stream.writeTextElement("Giorno",QString::number(c->getDataNascita().getGiorno()));
    stream.writeTextElement("Mese",QString::number(c->getDataNascita().getMese()));
    stream.writeTextElement("Anno",QString::number(c->getDataNascita().getAnno()));
    stream.writeEndElement();
    stream.writeTextElement("Colore",QString::number(c->getColore()));
    stream.writeEndElement();
}
