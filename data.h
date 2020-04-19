#ifndef DATA_H
#define DATA_H
#include<iostream>
#include <string>

enum settimana {sabato=0, domenica=1, lunedi=2, martedi=3, mercoledi=4, giovedi=5, venerdi=6};

class Data{
public:
    //costruttore di default
    Data();
    //costruttore a 3 parametri
    Data(unsigned int gg, unsigned int mm, unsigned int aa);
    //distruttore
    ~Data();
    //costruttore di copia
    Data(const Data& d);
    //overload dell'operatore d'assegnazione
    Data& operator=(const Data& d);


    //restituisce true se l'anno d'invocazione è bisestile
    bool bisestile() const;
    //restituisce la data completa sottoforma di stringa
    std::string getData() const;
    //modifica l'oggetto d'invocazione aumentandolo di g giorni
    void avanzaGiorni(unsigned int g);
    //modifica l'oggetto d'invocazione aumentandolo di m mesi
    void avanzaMesi(unsigned int m);
    //modifica l'oggetto d'invocazione aumentandolo di a anni
    void avanzaAnni(unsigned int a);
    //ritorna il numero di giorno per arrivare a fine mese dal giorno corrente
    unsigned int giorniFineMese() const;
    //conta gli anni bisestili prima della data d


    //ritorna il mese dell'oggetto d'invocazione
    unsigned int getMese() const;
    //ritorna il giorno dell'oggetto d'invocazione
    unsigned int getGiorno() const;
    //ritorna l'anno dell'oggetto d'invocazione
    unsigned int getAnno() const;
    //restituisce i giorni del mese dell'oggetto d'invocazione
    unsigned int getGiorniMese() const;
    //ritorna il giorno della settimana
    unsigned int getGiornoSettimana() const;
    //ritorna la data annuale del giorno considerato, ovvero il numero di giorni trascorsi dall'inizio dell'anno fino al giorno stesso (compreso)
    unsigned int getGiornoDellAnno() const;
    //ritorna il giorno della settimana sottoforma di stringa
    std::string getStringGs(int g) const;

    //setters
    void setGiorno(unsigned int x);
    void setMese(unsigned int x);
    void setAnno(unsigned int x);
    void setData(unsigned int gg,unsigned int mm,unsigned int aa);


    //overload operatori
    bool operator==(const Data& d) const;
    bool operator!=(const Data& d) const;
    bool operator<(const Data& d) const;
    bool operator>(const Data& d) const;

    unsigned int operator-(const Data& d) const;




    //costruttore da stringa??
    Data(const std::string& s);
    //costruttore a 4 parametri?
    //data(int gg, int mm, int aa, settimana gs);
    Data operator+(const Data& d) const;
    //postfissi
    Data operator++(int);
    Data operator--(int);
    //prefissi
    Data& operator++();
    Data& operator--();

private:
    unsigned int giorno, mese, anno;
    settimana giorno_settimana;

    static unsigned int countLeapYears(const Data &d);
};
//overload operatore di output
std::ostream& operator<<(std::ostream& os, const Data& d);
#endif // DATA_H
