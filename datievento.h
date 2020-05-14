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
    std::string titolo, luogo;
    std::vector<QDate> ricorrenze;
    QDate data;
    QTime inizio, fine;
    DatiEvento();
};

#endif // DATIEVENTO_H
