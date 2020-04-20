#include "data.h"

Data::Data():giorno(1),mese(1),anno(1980),giorno_settimana(martedi){}

//se l'input non è valido viene richiamato il costruttore di default
Data::Data(unsigned int gg, unsigned int mm, unsigned int aa):Data(){
    if(mm<=12){
        mese=mm;
        if(gg<=getGiorniMese())
            giorno=gg;
        anno=aa;
    }
    giorno_settimana=(settimana)getGiornoSettimana();
}

std::string Data::getData() const{
    return getStringGs(getGiornoSettimana())+" "+std::to_string(giorno)+"/"+std::to_string(mese)+"/"+std::to_string(anno);
}

unsigned int Data::getGiorniMese() const{
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

void Data::avanzaAnni(unsigned int a){
    anno+=a;
}

unsigned int Data::giorniFineMese() const
{
    unsigned int g= getGiorniMese();
    g-=getGiorno();
    return g;
}

void Data::avanzaMesi(unsigned int m){
    for(unsigned int i=0; i<m; i++){
        //se sono all'ultimo mese dell'anno passo all'anno successivo
        if(getMese()==12){
            mese=1;
            avanzaAnni(1);
        }
        else mese++;
    }
}

void Data::avanzaGiorni(unsigned int g){
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


unsigned int Data::getMese() const{
    return mese;
}

unsigned int Data::getGiorno() const{
    return giorno;
}

unsigned int Data::getAnno() const{
    return anno;
}

unsigned int Data::getGiornoSettimana() const {
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

unsigned int Data::getGiornoDellAnno() const
{
    unsigned int mm=getMese(), gg=0;
    //faccio una copia dell'obj d'invocazione per avere informazioni sull'anno di appartenenza (bisestile o meno)
    Data aux(*this);
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

std::string Data::getStringGs(int g) const{
    std::string gs[7]={"sabato","domenica","lunedi","martedi","mercoledi","giovedi","venerdi"};
    return gs[g];
}

void Data::setGiorno(unsigned int x)
{
    if(x>0 && x<getGiorniMese())
        giorno=x;
}

void Data::setMese(unsigned int x)
{
    if(x>0 && x<12)
        mese=x;
}

void Data::setAnno(unsigned int x)
{
    anno=x;
}

void Data::setData(unsigned int gg, unsigned int mm, unsigned int aa)
{
    giorno=gg;
    mese=mm;
    anno=aa;
}

bool Data::operator==(const Data &d) const
{
    return giorno==d.giorno && mese==d.mese && anno==d.anno;
}

bool Data::operator!=(const Data &d) const
{
    return giorno!=d.giorno || mese!=d.mese || anno!=d.anno;
}

bool Data::operator<(const Data &d) const
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

bool Data::operator>(const Data &d) const
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

unsigned int Data::operator-(const Data &d) const
{
    Data d1, d2;
    if(*this > d){
        d1=*this; d2=d;
    }
    else{
        d1=d; d2=*this;
    }
    // conta il numero di giorni prima della data dell'oggetto d'invocazione
    unsigned int n1 = d1.getAnno()*365 + d1.getGiornoDellAnno();

    // Since every leap year is of 366 days,
    // Add a day for every leap year
    n1 += countLeapYears(d1);

    unsigned int n2 = d2.getAnno()*365 + d2.getGiornoDellAnno();
    n2 += countLeapYears(d2);

    // return difference between two counts
    return (n1 - n2);
}

unsigned int Data::countLeapYears(const Data &d)
{
    int years = d.getAnno();

    // Check if the current year needs to be considered
    // for the count of leap years or not
    if (d.getMese() <= 2)
        years--;

    // An year is a leap year if it is a multiple of 4,
    // multiple of 400 and not a multiple of 100.
    return years / 4 - years / 100 + years / 400;
}

Data::~Data(){}

Data::Data(const Data &d): giorno(d.giorno), mese(d.mese), anno(d.anno), giorno_settimana(d.giorno_settimana){}

Data& Data::operator=(const Data &d){
    if(this!=&d){
        giorno=d.giorno;
        mese=d.mese;
        anno=d.anno;
        giorno_settimana=d.giorno_settimana;
    }
    return *this;
}

bool Data::bisestile() const{
    bool leap=false;
    //Se l'anno è divisibile per 4, ma non per 100, significa che è un anno bisestile
    if(anno%4==0 && anno%100!=0) leap=true;
    //Se l'anno preso in esame è divisibile sia per 4 sia per 100, esiste la possibilità che non sia bisestile
    if(anno%4==0 && anno%100==0)
        //Se è divisibile per 4, 100 e 400 è sicuramente un anno bisestile
        if(anno%4==0 && anno%100==0 && anno%400==0) leap=true;
    return leap;
}

std::ostream &operator<<(std::ostream &os, const Data &d){
    std::cout<<d.getStringGs(d.getGiornoSettimana())<<" "<<d.getGiorno()<<"/"<<d.getMese()<<"/"<<d.getAnno();
    return os;
}
