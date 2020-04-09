#include "data.h"
data::data(int gg=1, int mm=1, int aa=1980):giorno(gg),mese(mm),anno(aa){
}


std::string data::getData() const{
    return std::to_string(giorno)+"/"+std::to_string(mese)+"/"+std::to_string(anno);
}

