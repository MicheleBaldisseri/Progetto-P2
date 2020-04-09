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
    //costruttore di default
    data();
    //costruttore a 3 parametri
    data(int gg, int mm, int aa);
    //distruttore
    ~data();
    //costruttore di copia
    data(const data& d);
    //overload dell'operatore d'assegnazione
    data& operator=(const data& d);

    //restituisce true se l'anno d'invocazione è bisestile
    bool bisestile() const;
    //restituisce la data completa sottoforma di stringa
    std::string getData() const;
    //modifica l'oggetto d'invocazione
    void avanzaGiorno(int g);




    //costruttore da stringa??
    data(const std::string& s);

    void avanzaMese(int m);
    void avanzaAnno(int a);

    int getGiorno() const;
    int getMese() const;
    int getAnno() const;

    void setGiorno();
    void setMese();
    void setAnno();
    void setData(int, int, int);



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
