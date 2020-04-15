#ifndef DATA_H
#define DATA_H
#include<iostream>
#include <string>

enum settimana {sabato=0, domenica=1, lunedi=2, martedi=3, mercoledi=4, giovedi=5, venerdi=6};

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
    //modifica l'oggetto d'invocazione aumentandolo di g giorni
    void avanzaGiorni(unsigned int g);
    //modifica l'oggetto d'invocazione aumentandolo di m mesi
    void avanzaMesi(unsigned int m);
    //modifica l'oggetto d'invocazione aumentandolo di a anni
    void avanzaAnni(int a);


    //ritorna il mese dell'oggetto d'invocazione
    int getMese() const;
    //ritorna il giorno dell'oggetto d'invocazione
    int getGiorno() const;
    //ritorna l'anno dell'oggetto d'invocazione
    int getAnno() const;
    //restituisce i giorni del mese dell'oggetto d'invocazione
    int getGiorniMese() const;
    //ritorna il giorno della settimana
    int getGiornoSettimana() const;
    //ritorna la data annuale del giorno considerato, ovvero il numero di giorni trascorsi dall'inizio dell'anno fino al giorno stesso (compreso)
    int getGiornoDellAnno() const;

    void setGiorno(int x);
    void setMese(int x);
    void setAnno(int x);




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
    unsigned int giorno, mese, anno;
    settimana giorno_settimana;
};
//overload operatore di output
std::ostream& operator<<(std::ostream& os, const data& d);
#endif // DATA_H
