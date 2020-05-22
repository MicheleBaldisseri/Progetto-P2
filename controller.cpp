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

void Controller::dataFromWindow(DatiEvento *obj,bool modifica)
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


    if(modifica){
        int pos = view->getPos();
        vector<Lista<Evento*>::const_iterator> v = model->getSelezionati();
        bool er=model->erase((*(v[pos])));
        if(!er){
            view->showMessage(er,"Modifica","Errore nella modifica");
            return;
        }
    }

    bool done=model->insert(newEvento);
    if(done==false){
        if(modifica){
            view->showMessage(done,"Modifica","Errore nella modifica");
        }else{
            view->showMessage(done,"Evento già inserito","E' già presente questo evento.");
        }
    }else{
        if(modifica){
            view->showMessage(done,"Modifica","Evento modificato con successo!");
        }
    }

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
    DatiEvento* obj = new DatiEvento();

    obj->dataSelezionata=QDate(e->getDataInizio().getAnno(),e->getDataInizio().getMese(),e->getDataInizio().getGiorno());
    obj->titolo=e->getTitolo();
    obj->inizio=QTime(e->getDataInizio().getOre(),e->getDataInizio().getMinuti(),e->getDataInizio().getSecondi());
    obj->colore=(int)e->getColore();

    Promemoria* p = dynamic_cast<Promemoria*>(e);
    if(p){
        obj->type=0;
        obj->contenuto=p->getDesc();
    }

    Appuntamento* a = dynamic_cast<Appuntamento*>(e);
    if(a){
        obj->type=1;
        obj->fine=QTime(a->getDataFine().getOre(),a->getDataFine().getMinuti(),a->getDataFine().getSecondi());
        obj->luogo=a->getLuogo();
    }

    Compleanno* c = dynamic_cast<Compleanno*>(e);
    if(c){
        obj->type=2;
        obj->annoNascita=c->getDataNascita().getAnno();
    }

    Impegno* i = dynamic_cast<Impegno*>(e);
    if(i){
        obj->type=3;
        obj->fine=QTime(i->getDataFine().getOre(),i->getDataFine().getMinuti(),i->getDataFine().getSecondi());
    }

    view->initializeModifica(obj);
}























