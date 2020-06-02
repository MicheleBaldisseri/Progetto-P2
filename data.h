#ifndef DATA_H
#define DATA_H
#include<iostream>
#include <string>

enum settimana {sabato=0, domenica=1, lunedi=2, martedi=3, mercoledi=4, giovedi=5, venerdi=6};

class Data;
std::ostream& operator<<(std::ostream&, const Data&);

class Data{
    friend std::ostream& operator<<(std::ostream&, const Data&);
public:
    //costruttore default
    Data();
    /**
     * @brief costruttore completo
     * @param giorno
     * @param mese
     * @param anno
     */
    Data(const unsigned int& gg,const unsigned int& mm,const unsigned int& aa);
    //distruttore
    ~Data();
    //costruttore di copia
    Data(const Data& d);
    //overload dell'operatore d'assegnazione
    Data& operator=(const Data& d);

    /**
     * @brief determina se l'anno è bisestile
     * @return restituisce true se l'anno d'invocazione è bisestile
     */
    bool bisestile() const;
    /**
     * @return restituisce la data completa sottoforma di stringa
     */
    std::string getData() const;
    /**
     * @brief modifica l'oggetto d'invocazione aumentandone i giorni
     * @param giorni da aumentare
     */
    void avanzaGiorni(const unsigned int& g);
    /**
     * @brief modifica l'oggetto d'invocazione aumentandone i mesi
     * @param mesi da aumentare
     */
    void avanzaMesi(const unsigned int& m);
    /**
     * @brief modifica l'oggetto d'invocazione aumentandone gli anni
     * @param anni da aumentare
     */
    void avanzaAnni(const unsigned int& a);
    /**
     * @brief comunica quanti giorni mancano per arrivare a fine mese dal giorno corrente
     * @return ritorna il numero di giorno per arrivare a fine mese
     */
    unsigned int giorniFineMese() const;

    //getters
    unsigned int getMese() const;
    unsigned int getGiorno() const;
    unsigned int getAnno() const;
    /**
     * @return restituisce i giorni del mese dell'oggetto d'invocazione
     */
    unsigned int getGiorniMese() const;
    /**
     * @return ritorna il giorno della settimana
     */
    unsigned int getGiornoSettimana() const;
    /**
     * @return ritorna la data annuale del giorno considerato, ovvero il numero di giorni
     *          trascorsi dall'inizio dell'anno fino al giorno stesso (compreso)
     */
    unsigned int getGiornoDellAnno() const;
    /**
     * @return ritorna il giorno della settimana sottoforma di stringa
     */
    std::string getStringGs(const int& g) const;

    //setters
    void setGiorno(const unsigned int& x);
    void setMese(const unsigned int& x);
    void setAnno(const unsigned int& x);
    void setData(const unsigned int& gg,const unsigned int& mm,const unsigned int& aa);

    //overload operatori
    bool operator==(const Data& d) const;
    bool operator!=(const Data& d) const;
    bool operator<(const Data& d) const;
    bool operator>(const Data& d) const;
    /**
     * @return ritorna i giorni di differenza
     */
    unsigned int operator-(const Data& d) const;

private:
    unsigned int giorno, mese, anno;
    settimana giorno_settimana;
    /**
     * @brief metodo usato dall'operator-
     * @return ritorna il numero di anni bisestili tra l'anno 0 e quello dell'obj
     */
    static unsigned int countLeapYears(const Data &d);
};

//overload operatore di output
std::ostream& operator<<(std::ostream& os, const Data& d);

#endif // DATA_H
