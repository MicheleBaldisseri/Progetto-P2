#ifndef IMPORTA_H
#define IMPORTA_H
#include "appuntamento.h"
#include "impegno.h"
#include "compleanno.h"
#include "promemoria.h"
#include "lista.h"
#include "model.h"

class Importa
{
private:
    Lista<Evento*>l;
public:
    Importa(Lista<Evento*>& lista):l(lista){}
    bool Import(Model&);
    Promemoria* xmlToProm(QXmlStreamReader&);
    Impegno* xmlToImp(QXmlStreamReader&);
    Compleanno* xmlToComp(QXmlStreamReader&);
    Appuntamento* xmlToApp(QXmlStreamReader&);
    Dataora xmlToDataOra(QXmlStreamReader&);
    Data xmlToData(QXmlStreamReader&);
};

#endif // IMPORTA_H
