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
    //restituisce i giorni del mese dell'oggetto d'invocazione
    int getGiorniMese() const;
    //modifica l'oggetto d'invocazione aumentandolo di g giorni
    void avanzaGiorni(int g);
    //modifica l'oggetto d'invocazione aumentandolo di m mesi
    void avanzaMesi(int m);
    //modifica l'oggetto d'invocazione aumentandolo di a anni
    void avanzaAnni(int a);


    //ritorna il mese dell'oggetto d'invocazione
    int getMese() const;
    //ritorna il giorno dell'oggetto d'invocazione
    int getGiorno() const;
    //ritorna l'anno dell'oggetto d'invocazione
    int getAnno() const;


    void setGiorno();
    void setMese();
    void setAnno();




    //costruttore da stringa??
    data(const std::string& s);
    //costruttore a 4 parametri?
    //data(int gg, int mm, int aa, settimana gs);
    void setData(int, int, int);
    data operator+(const data&);
    data operator-(const data&);
    //postfissi
    data operator++(int);
    data operator--(int);
    //prefissi
    data& operator++();
    data& operator--();
    bool operator==(const data&) const;
    bool operator!=(const data&) const;
    bool operator<(const data&) const;
    bool operator>(const data&) const;
private:
    int giorno, mese, anno;
    settimana giorno_settimana;
};
//overload operatore di output
std::ostream& operator<<(std::ostream& os, const data& d);
#endif // DATA_H
