#ifndef IMPORTA_H
#define IMPORTA_H
#include <QXmlStreamReader>
#include <QFile>
#include "model.h"

class Model;

class Importa
{
public:
    Importa(){}
    bool import(Model&);//gestisce importazione dei dati, true se va a buon fine, false altrimenti
    Promemoria* xmlToProm(QXmlStreamReader&);//restituisce un Promemoria da file Xml
    Impegno* xmlToImp(QXmlStreamReader&);//restituisce un Impegno da file Xml
    Compleanno* xmlToComp(QXmlStreamReader&);//restituisce un Compleanno da file Xml
    Appuntamento* xmlToApp(QXmlStreamReader&);//restituisce un Appuntamento da file Xml
    Dataora xmlToDataOra(QXmlStreamReader&);//restituisce un Dataora da file Xml
    Data xmlToData(QXmlStreamReader&);//restituisce una Data da file Xml
};

#endif // IMPORTA_H
