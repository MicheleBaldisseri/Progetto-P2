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
    void appToXML(QXmlStreamWriter&,Appuntamento*);//esporta appuntamento
    void promToXML(QXmlStreamWriter&,Promemoria*);//esporta promemoria
    void impToXML(QXmlStreamWriter&,Impegno*);//esporta impegno
    void compToXML(QXmlStreamWriter&,Compleanno*);//esporta compleanno
};

#endif // ESPORTA_H

