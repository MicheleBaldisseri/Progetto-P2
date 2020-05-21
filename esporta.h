#ifndef ESPORTA_H
#define ESPORTA_H
#include <iostream>
#include <QFile>
#include "appuntamento.h"
#include "impegno.h"
#include "compleanno.h"
#include "promemoria.h"
#include "lista.h"

class Esporta
{
private:
    QFile lista;
    Lista<Evento*> l;
public:
    Esporta(Lista<Evento*>&);
    bool Export();
    void appToXML(QXmlStreamWriter&,Appuntamento*);
    void promToXML(QXmlStreamWriter&,Promemoria*);
    void impToXML(QXmlStreamWriter&,Impegno*);
    void compToXML(QXmlStreamWriter&,Compleanno*);
};

#endif // ESPORTA_H

