#include "evento.h"
#include <iostream>
using std::string;

Evento::Evento() : titolo(""), dataInizio(), colore(white){}

Evento::Evento(const string& tit, const Dataora& di, const Color& c) : titolo(tit), dataInizio(di), colore(c){
    std::size_t pos = 0;
    while ((pos = titolo.find('|',pos)) != std::string::npos) {
         titolo.replace(pos, 1, " ");
    }

}

void Evento::setColore(const Color& c){
    colore=c;
}

void Evento::setTitolo(const std::string & tit)
{
    titolo=tit;
    std::size_t pos = 0;
    while ((pos = titolo.find('|',pos)) != std::string::npos) {
         titolo.replace(pos, 1, " ");
    }
}

void Evento::setDataInizio(const Dataora & di)
{
    dataInizio=di;
}

Color Evento::getColore() const{
    return colore;
}

std::string Evento::getTitolo() const{
    return titolo;
}

Dataora Evento::getDataInizio() const{
    return dataInizio;
}

bool Evento::operator==(const Evento & e) const{
    return e.getTitolo()==titolo && e.getColore()==colore && e.getDataInizio()==dataInizio;
}

bool Evento::operator!=(const Evento & e) const{
    return !(*this==e);
}

bool Evento::operator>(const Evento & e) const{
    return dataInizio>e.getDataInizio();
}

bool Evento::operator<(const Evento & e) const{
    return dataInizio<e.getDataInizio();
}

std::ostream &operator<<(std::ostream & os, const Evento & e){
    //richiama la stampa polimorfa di tutti i campi dati
    return os<<e.descrizioneFull();
}
