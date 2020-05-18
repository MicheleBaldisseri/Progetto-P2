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
    Color c;

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

        //colore scelto dall'utente
        switch(obj->colore){
        case 0://red
            c=(Color)1;
            break;
        case 1://yellow
            c=(Color)3;
            break;
        case 2://green
            c=(Color)2;
            break;
        case 3://viola
            c=(Color)7;
            break;
        case 4://cyan
            c=(Color)6;
            break;
        case 5://white
            c=(Color)0;
            break;
        case 6://orange
            c=(Color)4;
            break;
        case 7://black
            c=(Color)5;
            break;
        case 8://grey
            c=(Color)8;
            break;
        }

        newEvento = new Promemoria(obj->titolo,i,obj->contenuto,c);

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

        //colore scelto dall'utente
        switch(obj->colore){
        case 0://green
            c=(Color)2;
            break;
        case 1://yellow
            c=(Color)3;
            break;
        case 2://red
            c=(Color)1;
            break;
        case 3://viola
            c=(Color)7;
            break;
        case 4://cyan
            c=(Color)6;
            break;
        case 5://white
            c=(Color)0;
            break;
        case 6://orange
            c=(Color)4;
            break;
        case 7://black
            c=(Color)5;
            break;
        case 8://grey
            c=(Color)8;
            break;
        }

        //creazione evento
        newEvento = new Appuntamento(obj->titolo,i,f,obj->luogo,c);

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

        //colore scelto dall'utente{white, red, green, yellow, orange, black, blue, purple, grey};
        switch(obj->colore){
        case 0://orange
            c=(Color)4;
            break;
        case 1://yellow
            c=(Color)3;
            break;
        case 2://red
            c=(Color)1;
            break;
        case 3://green
            c=(Color)2;
            break;
        case 4://cyan
            c=(Color)6;
            break;
        case 5://white
            c=(Color)0;
            break;
        case 6://purple
            c=(Color)7;
            break;
        case 7://black
            c=(Color)5;
            break;
        case 8://grey
            c=(Color)8;
            break;
        }

        //creazione evento
        newEvento = new Compleanno(obj->titolo,i,nascita,20,c);

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

        //colore scelto dall'utente
        switch(obj->colore){
        case 0://purple
            c=(Color)7;
            break;
        case 1://yellow
            c=(Color)3;
            break;
        case 2://red
            c=(Color)1;
            break;
        case 3://green
            c=(Color)2;
            break;
        case 4://cyan
            c=(Color)6;
            break;
        case 5://white
            c=(Color)0;
            break;
        case 6://orange
            c=(Color)4;
            break;
        case 7://black
            c=(Color)5;
            break;
        case 8://grey
            c=(Color)8;
            break;
        }

        //creazione nuovo evento
        newEvento=new Impegno(obj->titolo,i,f,mode,obj->ogni,obj->per,c);

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


