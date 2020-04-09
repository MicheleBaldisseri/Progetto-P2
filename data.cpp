#include "data.h"

data::data(int gg, int mm, int aa):giorno(gg),mese(mm),anno(aa){}

std::string data::getData() const{
    return std::to_string(giorno)+"/"+std::to_string(mese)+"/"+std::to_string(anno);
}

data::~data(){}

data::data(const std::string & s){}

data::data(const data &d): giorno(d.giorno), mese(d.mese), anno(d.anno){}

data &data::operator=(const data &d){
    if(this!=&d){
        giorno=d.giorno;
        mese=d.mese;
        anno=d.anno;
    }
    return *this;
}

std::ostream &operator<<(std::ostream &os, const data &d){
    std::cout<<d.giorno<<"/"<<d.mese<<"/"<<d.anno<<std::endl;
    return os;
}
