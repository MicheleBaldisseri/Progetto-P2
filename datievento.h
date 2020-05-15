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
    std::string titolo, luogo, colore;
    std::vector<QDate> ricorrenze;
    int type;//1=promemoria,2=appuntamento,3=impegno,4=compleanno
    QDate data;
    QTime inizio, fine;
    DatiEvento();
};

#endif // DATIEVENTO_H
