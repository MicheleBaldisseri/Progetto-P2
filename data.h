#ifndef DATA_H
#define DATA_H
#include<iostream>
#include <string>

enum settimana {lunedi, martedi, mercoledi, giovedi, venerdi, sabato, domenica};

class data;
std::ostream& operator<<(std::ostream&, const data&);

class data{
    friend std::ostream& operator<<(std::ostream& os, const data& d);
public:
    data(int gg=1, int mm=1, int aa=1980);
    ~data();
    data(const std::string& s);
    //costruttore di copia
    data(const data& d);
    //overload dell'operatore d'assegnazione
    data& operator=(const data& d);


    std::string getData() const;




    //distruttore

    void avanzaGiorno();
    void avanzaMese();
    void avanzaAnno();

    int getGiorno() const;
    int getMese() const;
    int getAnno() const;

    void setGiorno();
    void setMese();
    void setAnno();
    void setData(int, int, int);

    bool bisestile() const;

    data operator+(const data&);
    data operator-(const data&);
    //postfissi
    data operator++(int);
    data operator--(int);
    //prefissi
    data& operator++();
    data& operator--();
    bool operator==(const data&);
    bool operator!=(const data&);
    bool operator<(const data&);
    bool operator>(const data&);
private:
    int giorno, mese, anno;
    settimana giorno_settimana;
};
//overload operatore di output
std::ostream& operator<<(std::ostream& os, const data& d);
#endif // DATA_H
