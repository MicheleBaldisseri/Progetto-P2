#include "datievento.h"
#include <QDebug>

DatiEvento::DatiEvento(){}

DatiEvento *DatiEvento::fromStdString(std::string s){
    DatiEvento* obj = new DatiEvento();

    std::vector <std::string> tokens;
    std::stringstream check(s);
    std::string tok;

    while(std::getline(check,tok,'|')){
        tokens.push_back(tok);
    }

    /*for(int i = 0; i < tokens.size(); i++)
        std::cout << tokens[i] << '\n';*/

    obj->titolo=tokens[1];
    obj->dataSelezionata=QDate(std::stoi(tokens[4]),std::stoi(tokens[3]),std::stoi(tokens[2]));
    obj->inizio=QTime(std::stoi(tokens[5]),std::stoi(tokens[6]),std::stoi(tokens[7]));
    obj->colore=std::stoi(tokens[8]);

    if(tokens[0]=="Promemoria"){
        obj->type=0;
        obj->contenuto=tokens[9];
    }else if(tokens[0]=="Appuntamento"){
        obj->type=1;
        //TODO
    }else if(tokens[0]=="Compleanno"){
        obj->type=2;
        //TODO
    }else if(tokens[0]=="Impegno"){
        obj->type=3;
        //TODO
    }

    return obj;
}
