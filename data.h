#ifndef DATA_H
#define DATA_H

#include <string>
enum settimana {lunedi, martedi, mercoledi, giovedi, venerdi, sabato, domenica};

class data{
private:
    int giorno, mese, anno;
    //settimana giorno_s; come gestirlo?

public:
    //costruttori
    data(int=1, int=1, int=1980);
    data(const std::string&);
    //costruttore di copia
    data(const data&);
    //overload dell'operatore d'assegnazione
    data& operator=(const data&);
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
};
//overload operatore di output
std::ostream& operator<<(std::ostream&, const data&);
#endif // DATA_H
