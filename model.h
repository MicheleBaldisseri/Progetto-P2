#ifndef MODEL_H
#define MODEL_H
#include "evento.h"
#include "lista.h"
#include <vector>
class Model
{
private:
    Lista<Evento*> l;
    vector<Lista<Evento*>::const_iterator> selezionati;
public:
    bool modify(Lista<Evento*>::const_iterator,Evento*);//cerca evento, controlla se ci sono campi diversi e lo modifico
    bool insert(Evento*);//prima verifica che non ci sia già l'evento
    Lista<Evento*>::const_iterator search(Evento*) const;//ricerca se evento è già presente nella lista. Se ricorrente ritorna solo il primo della lista. nullptr se non lo trova
    bool erase(Evento*);//cerca l'evento e se c'è cancella da iteratore. Se evento ricorrente cancella tutte le ricorrenze. True se ha successo, false altrimenti.
    void showEvent(const Data&);//ritorna tutti gli eventi che si verificano nella data specificata
    bool esporta();//scrive lista su file, true se ha successo, false altrimenti
    bool importa();//legge da file, true se ha successo, false altrimenti

};

#endif // MODEL_H
