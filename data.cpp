#include "data.h"

data::data():giorno(1),mese(1),anno(1980),giorno_settimana(martedi){}

//se l'input non è valido viene richiamato il costruttore di default
data::data(unsigned int gg, unsigned int mm, unsigned int aa):data(){
    if(mm<=12){
        mese=mm;
        if(gg<=getGiorniMese())
            giorno=gg;
        anno=aa;
    }
    giorno_settimana=(settimana)getGiornoSettimana();
}

std::string data::getData() const{
    return getStringGs(getGiornoSettimana())+" "+std::to_string(giorno)+"/"+std::to_string(mese)+"/"+std::to_string(anno);
}

unsigned int data::getGiorniMese() const{
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

void data::avanzaAnni(unsigned int a){
    anno+=a;
}

void data::avanzaMesi(unsigned int m){
    for(unsigned int i=0; i<m; i++){
        //se sono all'ultimo mese dell'anno passo all'anno successivo
        if(getMese()==12){
            mese=1;
            avanzaAnni(1);
        }
        else mese++;
    }
}

void data::avanzaGiorni(unsigned int g){
    //salvo i giorni del mese corrente in una variabile
    unsigned int ggMese=getGiorniMese();
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


unsigned int data::getMese() const{
    return mese;
}

unsigned int data::getGiorno() const{
    return giorno;
}

unsigned int data::getAnno() const{
    return anno;
}

unsigned int data::getGiornoSettimana() const {
    return (anno+ ((anno-1)/4) - ((anno-1)/100) + ((anno-1)/400) + getGiornoDellAnno()) % 7;
    /*
    0	sabato
    1	domenica
    2	lunedì
    3	martedì
    4	mercoledì
    5	giovedì
    6	venerdì
    */
}

unsigned int data::getGiornoDellAnno() const
{
    unsigned int mm=getMese(), gg=0;
    //faccio una copia dell'obj d'invocazione per avere informazioni sull'anno di appartenenza (bisestile o meno)
    data aux(*this);
    for(unsigned int i=1; i<=mm; i++){
        //calcolo in base all'anno di appart. i giorni dei mesi precedenti a quello in cui mi trovo
        if(getMese() != i){
            aux.setMese(i);
            gg+=aux.getGiorniMese();
        }
        //aggiungo il giorno del mese in cui si trova la data
        else gg+=giorno;
    }
    return gg;
}

std::string data::getStringGs(int g) const{
    std::string gs[7]={"sabato","domenica","lunedi","martedi","mercoledi","giovedi","venerdi"};
    return gs[g];
}

void data::setGiorno(unsigned int x)
{
    if(x>0 && x<getGiorniMese())
        giorno=x;
}

void data::setMese(unsigned int x)
{
    if(x>0 && x<12)
        mese=x;
}

void data::setAnno(unsigned int x)
{
    anno=x;
}

void data::setData(unsigned int gg, unsigned int mm, unsigned int aa)
{
    giorno=gg;
    mese=mm;
    anno=aa;
}

bool data::operator==(const data &d) const
{
    return giorno==d.giorno && mese==d.mese && anno==d.anno;
}

bool data::operator!=(const data &d) const
{
    return giorno!=d.giorno || mese!=d.mese || anno!=d.anno;
}

bool data::operator<(const data &d) const
{
    return anno<d.anno?
                true : (
                    anno==d.anno?
                        (mese<d.mese?
                             true : (
                                 mese==d.mese?
                                     (giorno<d.giorno?
                                          true : false)
                                   : false))
                      : false);
}

bool data::operator>(const data &d) const
{
    return anno>d.anno?
                true : (
                    anno==d.anno?
                        (mese>d.mese?
                             true : (
                                 mese==d.mese?
                                     (giorno>d.giorno?
                                          true : false)
                                   : false))
                      : false);
}

data::~data(){}

data::data(const data &d): giorno(d.giorno), mese(d.mese), anno(d.anno), giorno_settimana(d.giorno_settimana){}

data &data::operator=(const data &d){
    if(this!=&d){
        giorno=d.giorno;
        mese=d.mese;
        anno=d.anno;
        giorno_settimana=d.giorno_settimana;
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
    std::cout<<d.getStringGs(d.getGiornoSettimana())<<" "<<d.giorno<<"/"<<d.mese<<"/"<<d.anno<<std::endl;
    return os;
}
