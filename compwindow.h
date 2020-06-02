#ifndef COMPWINDOW_H
#define COMPWINDOW_H

#include <QDialog>
#include <QWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QComboBox>
#include <QGroupBox>
#include <QDialogButtonBox>
#include <QFormLayout>
#include <QLabel>
#include <QColor>
#include "datievento.h"
#include <QSpinBox>
#include <QMessageBox>

class CompWindow : public QDialog
{
    Q_OBJECT
public:
    /**
     * @brief costruttore completo
     * @param puntatore alla main window
     * @param data selezionata nel calendario
     * @param puntatoer all'obj che contiene i dati dell'evento da modificare
     */
    explicit CompWindow(QWidget *parent, const QDate& selDate, DatiEvento* e = nullptr);
    ~CompWindow();
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
    QLineEdit* title;
    QSpinBox* setYear;
    QDialogButtonBox *buttonBox;
    QVBoxLayout *mainLayout;
    QGroupBox *formGroupBox;
    /**
     * @brief inserisce gli elementi all'interno della finestra secondaria
     */
    void addCompItems();
    /**
     * @brief inserisce i dati dell'evento che si vuole modificare nel form
     * @param dati dell'evento che si vuole modificare
     */
    void setForm(DatiEvento* obj);
};
#endif // COMPWINDOW_H
