#include "importa.h"

#include <QFile>
bool Importa::Import(Model& m)
{
    QFile lista("lista.xml");
        if(!lista.open(QIODevice::ReadOnly | QIODevice::Text)){
            lista.open(QIODevice::ReadWrite | QIODevice::Text);//crea un file se non è presente
            lista.close();
            return false;
        }
        else{
            QXmlStreamReader reader(&lista);
            Evento*e;
            if (reader.readNextStartElement()){
                if(reader.name()=="Evento"){
                    while(reader.readNextStartElement()){
                        if(reader.name()=="Promemoria"){
                            e=this->xmlToProm(reader);
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
                                        reader.skipCurrentElement();
                                }
                            }
                        }
                    m.insert(e);
                }

                lista.close();
                return true;
                }
                else{
                    reader.raiseError(QObject::tr("Incorrect file"));
                    return false;
                }
            }
            else return false;
        }
}

Promemoria *Importa::xmlToProm(QXmlStreamReader &stream)
{
    string tit,desc;
    Dataora dat;
    int col;
    while(stream.readNextStartElement()){
        if(stream.name()=="Titolo")
            tit=stream.readElementText().toStdString();
        else{
            if(stream.name()=="DataInizio")
                dat=xmlToDataOra(stream);
            else{
                if(stream.name()=="Desc")
                    desc=stream.readElementText().toStdString();
                else{
                    if(stream.name()=="Colore")
                        col=stoi(stream.readElementText().toStdString());
                }
            }
        }
    }
    return new Promemoria(tit,dat,desc,(Color)col);
}

Impegno *Importa::xmlToImp(QXmlStreamReader &stream)
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
                in=xmlToDataOra(stream);
            else{
                if(stream.name()=="DataFine")
                    fi=xmlToDataOra(stream);
                else{
                    if(stream.name()=="Colore")
                        col=stoi(stream.readElementText().toStdString());
                    else{
                        if(stream.name()=="Ricorrenze"){
                            while(stream.readNextStartElement()){
                                if(stream.name()=="Ricor"){
                                    v.push_back(Data(xmlToData(stream)));
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

Compleanno *Importa::xmlToComp(QXmlStreamReader &stream)
{
    string tit;
    Dataora in;
    Data nas;
    int col;
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
                        col=stoi(stream.readElementText().toStdString());
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
    int col;
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
                            col=stoi(stream.readElementText().toStdString());
                }
            }
        }
    }
    return new Appuntamento(tit,in,fi,luogo,(Color)col);
}

Dataora Importa::xmlToDataOra(QXmlStreamReader &stream)
{
    int g,m,a,o,mp,s;
    while(stream.readNextStartElement()){
        if(stream.name()=="Giorno")
            g=stoi(stream.readElementText().toStdString());
        else{
            if(stream.name()=="Mese")
                m=stoi(stream.readElementText().toStdString());
            else{
                if(stream.name()=="Anno")
                    a=stoi(stream.readElementText().toStdString());
                else{
                    if(stream.name()=="Ora")
                        o=stoi(stream.readElementText().toStdString());
                    else{
                        if(stream.name()=="Minuti")
                            mp=stoi(stream.readElementText().toStdString());
                        else
                            s=stoi(stream.readElementText().toStdString());
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
    int g,m,a;
    while(stream.readNextStartElement()){
        if(stream.name()=="Giorno")
            g=stoi(stream.readElementText().toStdString());
        else{
            if(stream.name()=="Mese")
                m=stoi(stream.readElementText().toStdString());
            else{
                if(stream.name()=="Anno")
                    a=stoi(stream.readElementText().toStdString());
            }
        }
    }
    Data d(g,m,a);
    return d;
}
