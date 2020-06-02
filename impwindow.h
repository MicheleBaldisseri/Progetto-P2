#ifndef IMPWINDOW_H
#define IMPWINDOW_H

#include <QDialog>
#include <QWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QDateTime>
#include <QComboBox>
#include <QGroupBox>
#include <QDialogButtonBox>
#include <QFormLayout>
#include <QLineEdit>
#include <QTimeEdit>
#include <QDateTimeEdit>
#include <QSpinBox>
#include "datievento.h"
#include <QColor>
#include <QMessageBox>

class ImpWindow : public QDialog
{
    Q_OBJECT
public:
    /**
     * @brief costruttore completo
     * @param puntatore alla main window
     * @param data selezionata nel calendario
     * @param puntatore all'obj che contiene i dati dell'evento da modificare
     */
    explicit ImpWindow(QWidget *parent, const QDate& selDate, DatiEvento* e = nullptr);
    ~ImpWindow();
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
    QDialogButtonBox *buttonBox;
    QVBoxLayout *mainLayout;
    QGroupBox *formGroupBox;
    QGroupBox *RicorrenzaGroupBox;
    QDate date;
    QComboBox* ricChoise,* colorChoise;
    QSpinBox* intOcc, *intGiorni;
    QLineEdit* title;
    QTimeEdit* setTimeBegin, *setTimeEnd;
    /**
     * @brief inserisce gli elementi all'interno della finestra secondaria
     */
    void addImpItems();
    /**
     * @brief inserisce i dati dell'evento che si vuole modificare nel form
     * @param dati dell'evento che si vuole modificare
     */
    void setForm(DatiEvento* obj);
};

#endif // IMPWINDOW_H
