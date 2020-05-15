#include "controller.h"

Controller::Controller(Model* m, QObject* parent)
        : QObject(parent), view(nullptr), model(m) {}

void Controller::setView(MainWindow* v) { view = v; }

void Controller::updateList(const QDate& date){
    view->clearList();

    Data d = Data(date.day(),date.month(),date.year());
    model->showEvent(d);
    vector<Lista<Evento*>::const_iterator> v = model->getSelezionati();

    for(unsigned int i=0;i<v.size();i++){
        view->addEventList((*(v[i]))->descrizioneMin(),(*(v[i]))->getColore());
    }
}

void Controller::exportEvents()
{
    //richiamo model.export()
    bool done=model->esporta();
    //comunico alla vista il risultato per mostrare un messaggio all'utente
    if(done){
        view->showMessage(done,"Salvataggio", "Tutti gli eventi sono stati salvati con successo!");
    }else{
        view->showMessage(done,"Salvataggio", "Impossibile salvare il file.");
    }
}

void Controller::dataFromWindow(DatiEvento *obj)
{
    Evento* eI = new Impegno(obj->titolo,Dataora(25,5,2020,11,11,11),Dataora(25,5,2020,12,12,12),giorno,2,3);
    model->insert(eI);
    view->updateList();
}

void Controller::eliminaEvento(const int &pos){
    vector<Lista<Evento*>::const_iterator> v = model->getSelezionati();
    bool done=model->erase((*(v[pos])));
    if(done){
        view->showMessage(done,"Eliminazione", "Evento eliminato con successo!");
    }else{
        view->showMessage(done,"Salvataggio", "Errore durante l'eliminazione");
    }
    view->updateList();
}
