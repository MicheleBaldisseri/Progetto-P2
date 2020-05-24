#include "importa.h"

bool Importa::import(Model& m)
{
    QFile lista("lista.xml");
        if(!lista.open(QIODevice::ReadOnly | QIODevice::Text)){
            lista.open(QIODevice::ReadWrite | QIODevice::Text);//crea un file vuoto se non è presente
            lista.close();
            return false;
        }
        else{
            QXmlStreamReader reader(&lista);
            Evento*e=nullptr;
            if (reader.readNextStartElement()){
                if(reader.name()=="Evento"){//reader accede al tag Evento
                    while(reader.readNextStartElement()){//ciclo che scorre i tag all'interno di Evento
                        if(reader.name()=="Promemoria"){//verifica il tag e direziona la chiamata alla funzione più oppurtuna
                            e=this->xmlToProm(reader);//in base al tipo di evento
                        }
                        else{
                            if(reader.name()=="Appuntamento"){
                                e=this->xmlToApp(reader);
                            }
                            else{
                                if(reader.name()=="Impegno"){
                                    e=this->xmlToImp(reader);
                                }
                                else{
                                    if(reader.name()=="Compleanno"){
                                        e=this->xmlToComp(reader);
                                    }
                                    else
                                        reader.skipCurrentElement();//se il tag è sconosciuto passa all'elemento successivo
                                }
                            }
                        }
                        if(e!=nullptr)
                            m.insert(e);//inserisce e nel modello utilizzando insert
                }

                lista.close();//chiusura del QFile per evitare conflitti
                return true;
                }
                else{
                    reader.raiseError(QObject::tr("Incorrect file"));//Se il file non è scritto in modo corretto viene
                    return false;//sollevata un eccezione
                }
            }
            else return false;//se file è vuoto restituisce false
        }
}

Promemoria *Importa::xmlToProm(QXmlStreamReader &stream)
{
    string tit,desc;//variabili dove salvare il testo letto
    Dataora dat;
    int col=0;
    while(stream.readNextStartElement()){//scorre tutti i tag all'interno di Promemoria
        if(stream.name()=="Titolo") //Per ogni tag viene assegnato il testo trovato alla variabile corrispondente
            tit=stream.readElementText().toStdString();//QString convertita in std::string
        else{
            if(stream.name()=="DataInizio")
                dat=xmlToDataOra(stream);
            else{
                if(stream.name()=="Desc")
                    desc=stream.readElementText().toStdString();
                else{
                    if(stream.name()=="Colore")
                        col=stream.readElementText().toInt();//QString convertita in int
                    else return nullptr;//se file scritto in modo non corretto ritorna un nullptr
                }
            }
        }
    }
    return new Promemoria(tit,dat,desc,(Color)col);//creazione del puntatore con le variabili
}

Impegno *Importa::xmlToImp(QXmlStreamReader &stream)
{
    string tit;
    Dataora in,fi;
    int col=0;
    vector<Data> v;
    while(stream.readNextStartElement()){
        if(stream.name()=="Titolo")
            tit=stream.readElementText().toStdString();
        else{
            if(stream.name()=="DataInizio")
                in=xmlToDataOra(stream);
            else{
                if(stream.name()=="DataFine")
                    fi=xmlToDataOra(stream);
                else{
                    if(stream.name()=="Colore")
                        col=stream.readElementText().toInt();
                    else{
                        if(stream.name()=="Ricorrenze"){
                            while(stream.readNextStartElement()){
                                if(stream.name()=="Ricor"){
                                    v.push_back(Data(xmlToData(stream)));
                                }
                                else return nullptr;//se file scritto in modo non corretto ritorna un nullptr
                            }
                        }
                    }
                }
            }
        }
    }
    return new Impegno (tit,in,fi,v,(Color)col);
}

Compleanno *Importa::xmlToComp(QXmlStreamReader &stream)
{
    string tit;
    Dataora in;
    Data nas;
    int col=0;
    while(stream.readNextStartElement()){
        if(stream.name()=="Titolo")
            tit=stream.readElementText().toStdString();
        else{
            if(stream.name()=="DataInizio")
                in=xmlToDataOra(stream);
            else{
                if(stream.name()=="DataNascita")
                    nas=xmlToData(stream);
                else{
                    if(stream.name()=="Colore")
                        col=stream.readElementText().toInt();
                    else return nullptr;//se file scritto in modo non corretto ritorna un nullptr
                }
            }
        }
    }
    return new Compleanno(tit,in,nas,20,(Color)col);
}

Appuntamento *Importa::xmlToApp(QXmlStreamReader &stream)
{
    string tit,luogo;
    Dataora in,fi;
    int col=0;
    while(stream.readNextStartElement()){
        if(stream.name()=="Titolo")
            tit=stream.readElementText().toStdString();
        else{
            if(stream.name()=="DataInizio")
                in=xmlToDataOra(stream);
            else{
                if(stream.name()=="DataFine")
                    fi=xmlToDataOra(stream);
                else{
                    if(stream.name()=="Luogo")
                        luogo=stream.readElementText().toStdString();
                    else
                        if(stream.name()=="Colore")
                            col=stream.readElementText().toInt();
                        else return nullptr;//se file scritto in modo non corretto ritorna un nullptr
                }
            }
        }
    }
    return new Appuntamento(tit,in,fi,luogo,(Color)col);
}

Dataora Importa::xmlToDataOra(QXmlStreamReader &stream)
{
    int g=0,m=0,a=0,o=0,mp=0,s=0;//variabili dove salvare i numeri letti
    while(stream.readNextStartElement()){
        if(stream.name()=="Giorno")
            g=stream.readElementText().toInt();//conversione di QString in int
        else{
            if(stream.name()=="Mese")
                m=stream.readElementText().toInt();
            else{
                if(stream.name()=="Anno")
                    a=stream.readElementText().toInt();
                else{
                    if(stream.name()=="Ora")
                        o=stream.readElementText().toInt();
                    else{
                        if(stream.name()=="Minuti")
                            mp=stream.readElementText().toInt();
                        else
                            if(stream.name()=="Secondi")
                                s=stream.readElementText().toInt();
                    }
                }
            }
        }
    }
    Dataora d(g,m,a,o,mp,s);
    return d;
}

Data Importa::xmlToData(QXmlStreamReader &stream)
{
    int g=0,m=0,a=0;
    while(stream.readNextStartElement()){
        if(stream.name()=="Giorno")
            g=stream.readElementText().toInt();
        else{
            if(stream.name()=="Mese")
                m=stream.readElementText().toInt();
            else{
                if(stream.name()=="Anno")
                    a=stream.readElementText().toInt();
            }
        }
    }
    Data d(g,m,a);
    return d;
}
