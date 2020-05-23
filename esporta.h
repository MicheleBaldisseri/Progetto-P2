#ifndef ESPORTA_H
#define ESPORTA_H
#include <iostream>
#include <QFile>
#include <QXmlStreamWriter>
#include "model.h"

class Esporta
{
private:
    QFile lista;//QFile dove salvare
    Lista<Evento*> l;
public:
    Esporta(Lista<Evento*>&);
    bool esport();//true se l'export va a buon fine, false altrimenti
    void appToXML(QXmlStreamWriter&,Appuntamento*);//esporta appuntamento
    void promToXML(QXmlStreamWriter&,Promemoria*);//esporta promemoria
    void impToXML(QXmlStreamWriter&,Impegno*);//esporta impegno
    void compToXML(QXmlStreamWriter&,Compleanno*);//esporta compleanno
};

#endif // ESPORTA_H

