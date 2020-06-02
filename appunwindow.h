#ifndef APPUNWINDOWS_H
#define APPUNWINDOWS_H

#include <QDialog>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QFormLayout>
#include <QGroupBox>
#include <QLabel>
#include <QLineEdit>
#include <QComboBox>
#include <QSpinBox>
#include <QDialog>
#include <QDialogButtonBox>
#include <QPushButton>
#include <QTimeEdit>
#include <QColor>
#include "datievento.h"
#include <QMessageBox>

class AppunWindow : public QDialog
{
    Q_OBJECT
public:
    /**
     * @brief costruttore completo
     * @param puntatore alla main window
     * @param data selezionata nel calendario
     * @param puntatore all'obj che contiene i dati dell'evento da modificare
     */
    explicit AppunWindow(QWidget *parent, const QDate& selDate, DatiEvento* e = nullptr);
    ~AppunWindow();
public slots:
    /**
     * @brief accoglie il segnale emesso dal form quando l'utente inserisce/modifica i dati
     */
    void creaEvento();
signals:
    /**
     * @brief segnale emesso quando l'evento è stato creato/modificato, i dati vengono inviati alla main window
     * @param puntatore all'obj contenente i dati
     * @param bool per dividere le azioni, true sse è una modifica
     */
    void eventoInserito(DatiEvento*,bool);
private:
    bool modifica;
    QDate date;
    QComboBox* colorChoise;
    QLineEdit* title, * location;
    QTimeEdit* setTimeBegin,* setTimeEnd;
    QGroupBox *formGroupBox;
    QDialogButtonBox *buttonBox;

    /**
     * @brief inserisce gli elementi all'interno della finestra secondaria
     */
    void createFormGroupBox();
    /**
     * @brief inserisce i dati dell'evento che si vuole modificare nel form
     * @param dati dell'evento che si vuole modificare
     */
    void setForm(DatiEvento* obj);
};

#endif // APPUNWINDOWS_H
