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
    Evento* newEvento;

    switch (obj->type) {
    case 0:
    {
        //---- PROMEMORIA -------
        Dataora i;
        //conversione QDate->Dataora
        i.setData(obj->dataSelezionata.day(),obj->dataSelezionata.month(),obj->dataSelezionata.year());
        i.setOre(obj->inizio.hour());
        i.setMinuti(obj->inizio.minute());
        i.setSecondi(obj->inizio.second());

        //creazione evento
        newEvento = new Promemoria(obj->titolo,i,obj->contenuto,(Color)obj->colore);

        break;
    }
  //---------------------------------------------------------------
    case 1:
    {
        //---- APPUNTAMENTO -------
        Dataora i,f;
        i.setData(obj->dataSelezionata.day(),obj->dataSelezionata.month(),obj->dataSelezionata.year());
        i.setOre(obj->inizio.hour());
        i.setMinuti(obj->inizio.minute());
        i.setSecondi(obj->inizio.second());
        f=i;
        f.setOre(obj->fine.hour());
        f.setMinuti(obj->fine.minute());
        f.setSecondi(obj->fine.second());

        //creazione evento
        newEvento = new Appuntamento(obj->titolo,i,f,obj->luogo,(Color)obj->colore);

        break;
    }
  //---------------------------------------------------------------
    case 2:
    {
        //---- COMPLEANNO -------
        Dataora i;
        //conversione QDate->Dataora
        i.setData(obj->dataSelezionata.day(),obj->dataSelezionata.month(),obj->dataSelezionata.year());
        Data nascita;
        nascita.setData(obj->dataSelezionata.day(),obj->dataSelezionata.month(),obj->annoNascita);

        //creazione evento
        newEvento = new Compleanno(obj->titolo,i,nascita,20,(Color)obj->colore);

        break;
    }
  //---------------------------------------------------------------
    case 3:
    {
        //---- IMPEGNO-------
        Dataora i,f;
        //conversione QDate->Dataora
        i.setData(obj->dataSelezionata.day(),obj->dataSelezionata.month(),obj->dataSelezionata.year());
        i.setOre(obj->inizio.hour());
        i.setMinuti(obj->inizio.minute());
        i.setSecondi(obj->inizio.second());
        f=i;
        f.setOre(obj->fine.hour());
        f.setMinuti(obj->fine.minute());
        f.setSecondi(obj->fine.second());

        //modalità ricorrenza
        ModeRicorrenza mode;
        if(obj->tipo==0)
            mode=giorno;
        else if(obj->tipo==1)
            mode=settimana;
        else
            mode=mese;

        //creazione nuovo evento
        newEvento=new Impegno(obj->titolo,i,f,mode,obj->ogni,obj->per,(Color)obj->colore);

        break;
    }
    }
    //----------- end switch eventi -----------------

    bool done=model->insert(newEvento);
    if(done==false)
        view->showMessage(done,"Evento già inserito","E' già presente questo evento.");
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

void Controller::modificaEvento(const int &pos){
    vector<Lista<Evento*>::const_iterator> v = model->getSelezionati();
    Evento* e = (*(v[pos]))->clone();
    std::cout<<e->descrizioneFull();
}


