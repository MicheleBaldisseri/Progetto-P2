#include "model.h"

bool Model::insert(Evento *e)
{
    if(search(e)==nullptr){//se search restituisce nullptr significa che l'evento non esiste dunque
        l.push_back(e);    // inserisce e
        return true;
    }
    else return false;
}

Lista<SmartEvento>::const_iterator Model::search(Evento *e)const
{
    Lista<SmartEvento>::const_iterator find=nullptr;//iteratore utilizzato per la restituzione dell'occorrenza
    for(Lista<SmartEvento>::const_iterator cit=l.begin();cit!=l.end()&&find==nullptr; ++cit){
        if(**cit==*e){
            find=cit;
        }
    }

    return find;
}

bool Model::erase(Evento *e)
{
    Lista<SmartEvento>::const_iterator find=search(e);//se search ritorna un'occorrenza allora viene cancellato l'evento
    if(find!=nullptr){
        find=l.erase(find);
        return true;
    }
    else{
        throw new std::invalid_argument("Impossibile procedere con l'eliminazione: evento non presente");
        return false;
    }
}

void Model::showEvent(const Data & d)
{
    selezionati.clear();//selezionati viene prima liberata in caso ci fossero già degli eventi
    for(Lista<SmartEvento>::const_iterator cit=l.begin();cit!=l.end();++cit){//ciclo che verifica tutta la Lista
        EventoRicorrente*r=dynamic_cast<EventoRicorrente*>((*cit).operator->());

        if(d==(*cit)->getDataInizio()){//
            selezionati.push_back(cit);
        }

        if(r){
            vector<Data>* v=r->getRicorrenze();
            for(vector<Data>::const_iterator c=v->begin();c!=v->end();++c){//viene passato tutto il vettore per verificare
                if(*c==d)                                                  //se ci sono match tra le ricorrenze
                    selezionati.push_back(cit);
            }
        }
    }
}

bool Model::esporta()
{
    Esporta lista(l);//crea una lista di classe Esporta passandogli la lista da cui stampare i dati
        if(lista.esport())//se esport va a buon fine restituisce vero
            return true;
        else
            return false;

}

bool Model::importa()
{
    Importa lista;//crea una lista di classe Importa
    if(lista.import(*this))//se import va a buon fine restituisce vero
        return true;
    else
        return false;
}

vector<Lista<SmartEvento>::const_iterator> Model::getSelezionati() const{
    return selezionati;
}

Lista<SmartEvento> Model::getl() const{
    return l;
}
