#include "data.h"

data::data():giorno(1),mese(1),anno(1980){}

data::data(int gg, int mm, int aa){
    if(mm<=12){
        mese=mm;
        if(gg<=getGiorniMese())
            giorno=gg;
        anno=aa;
    }
    else data();
}

std::string data::getData() const{
    return std::to_string(giorno)+"/"+std::to_string(mese)+"/"+std::to_string(anno);
}

int data::getGiorniMese() const{
    int gg;
    switch(mese){
        case(1): case(3): case(5): case(7): case(8): case(10): case(12):
            gg=31;
            break;
        case(2):
            bisestile()? gg=29 : gg=28;
            break;
        case(4): case(6): case(9): case(11):
            gg=30;
            break;
    }
    return gg;
}

void data::avanzaAnni(int a){
    anno+=a;
}

void data::avanzaMesi(int m){
    for(unsigned int i=0; i<m; i++){
        //se sono all'ultimo mese dell'anno passo all'anno successivo
        if(getMese()==12){
            mese=1;
            avanzaAnni(1);
        }
        else mese++;
    }
}

void data::avanzaGiorni(int g){
    //salvo i giorni del mese corrente in una variabile
    int ggMese=getGiorniMese();
    //aggiungo i giorni con un ciclo
    for(unsigned int i=0; i<g; i++){
        giorno++;
        //se arrivo a fine mese passo al successivo
        if(giorno>ggMese){
            //se sono a fine anno passo al successivo
            if(getMese()==12){
                avanzaAnni(1);
                mese=1;
                giorno=1;
                //aggiorno la variabile a Gennaio
                ggMese=getGiorniMese();
            } else {
                mese++;
                //aggiorno la variabile al nuovo mese
                ggMese=getGiorniMese();
                //parto dal primo
                giorno=1;
            }
        }
    }
}


int data::getMese() const{
    return mese;
}

int data::getGiorno() const{
    return giorno;
}

int data::getAnno() const{
    return anno;
}

data::~data(){}

data::data(const data &d): giorno(d.giorno), mese(d.mese), anno(d.anno){}

data &data::operator=(const data &d){
    if(this!=&d){
        giorno=d.giorno;
        mese=d.mese;
        anno=d.anno;
    }
    return *this;
}

bool data::bisestile() const{
    bool leap=false;
    //Se l'anno è divisibile per 4, ma non per 100, significa che è un anno bisestile
    if(anno%4==0 && anno%100!=0) leap=true;
    //Se l'anno preso in esame è divisibile sia per 4 sia per 100, esiste la possibilità che non sia bisestile
    if(anno%4==0 && anno%100==0)
        //Se è divisibile per 4, 100 e 400 è sicuramente un anno bisestile
        if(anno%4==0 && anno%100==0 && anno%400==0) leap=true;
    return leap;
}

std::ostream &operator<<(std::ostream &os, const data &d){
    std::cout<<d.giorno<<"/"<<d.mese<<"/"<<d.anno<<std::endl;
    return os;
}
