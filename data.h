#ifndef DATA_H
#define DATA_H

#include <string>

enum settimana {lunedi, martedi, mercoledi, giovedi, venerdi, sabato, domenica};

class data{
public:
    //costruttori
    data(int gg, int mm, int aa);
    data(const std::string& s);

    //costruttore di copia
    data(const data& d);
    //overload dell'operatore d'assegnazione
    data& operator=(const data& d);
    //distruttore
    ~data();

    void avanzaGiorno();
    void avanzaMese();
    void avanzaAnno();

    int getGiorno() const;
    int getMese() const;
    int getAnno() const;
    std::string getData() const;

    void setGiorno();
    void setMese();
    void setAnno();
    void setData(int, int, int);

    bool bisestile() const;

    data operator+(const data& d);
    data operator-(const data& d);
    //postfissi
    data operator++(int);
    data operator--(int);
    //prefissi
    data& operator++();
    data& operator--();
    bool operator==(const data& d);
    bool operator!=(const data& d);
    bool operator<(const data& d);
    bool operator>(const data& d);
private:
    int giorno, mese, anno;
    settimana giorno_settimana;
};

//overload operatore di output
std::ostream& operator<<(std::ostream&, const data&);

#endif // DATA_H
