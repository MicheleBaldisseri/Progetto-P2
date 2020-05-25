#ifndef PROMWINDOW_H
#define PROMWINDOW_H

#include <QDialog>
#include <QPlainTextEdit>
#include <QWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QComboBox>
#include <QGroupBox>
#include <QDialogButtonBox>
#include <QFormLayout>
#include <QLineEdit>
#include <QTimeEdit>
#include <QColor>
#include <QMessageBox>
#include "datievento.h"

class PromWindow : public QDialog
{
    Q_OBJECT
public:
    /**
     * @brief costruttore completo
     * @param puntatore alla main window
     * @param data selezionata nel calendario
     * @param puntatore all'obj che contiene i dati dell'evento da modificare
     */
    explicit PromWindow(QWidget *parent, const QDate& selDate, DatiEvento* e = nullptr);
    ~PromWindow();
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
    QTimeEdit* setTime;
    QDialogButtonBox *buttonBox;
    QVBoxLayout *mainLayout;
    QGroupBox *formGroupBox;
    QPlainTextEdit *bigEditor;
    /**
     * @brief inserisce gli elementi all'interno della finestra secondaria
     */
    void addPromItems();
    /**
     * @brief inserisce i dati dell'evento che si vuole modificare nel form
     * @param dati dell'evento che si vuole modificare
     */
    void setForm(DatiEvento* obj);
};

#endif // PROMWINDOW_H


