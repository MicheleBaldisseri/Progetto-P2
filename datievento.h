#ifndef DATIEVENTO_H
#define DATIEVENTO_H
#include <string>
#include <QDate>
#include <QTime>
#include <QDateTime>
#include <vector>

class DatiEvento
{
public:
    std::string titolo, luogo, contenuto;
    //std::vector<QDate> ricorrenze;
    int type;//0=promemoria,1=appuntamento,2=compleanno,3=impegno
    QDate dataSelezionata;
    QTime inizio, fine;
    DatiEvento();
    int ogni, tipo, per, colore, annoNascita;
};

#endif // DATIEVENTO_H
