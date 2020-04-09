#include "data.h"

data::data():giorno(0),mese(0),anno(0){}

data::data(int gg, int mm, int aa):giorno(gg),mese(mm),anno(aa){}

std::string data::getData() const{
    return std::to_string(giorno)+"/"+std::to_string(mese)+"/"+std::to_string(anno);
}

void data::avanzaAnno(int a){
    anno+=a;
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
