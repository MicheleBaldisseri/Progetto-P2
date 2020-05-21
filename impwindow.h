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
    explicit ImpWindow(QWidget *parent, const QDate& selDate, DatiEvento* e = nullptr);
    ~ImpWindow();
public slots:
    void creaEvento();
signals:
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

    void addImpItems();
    void setForm(DatiEvento* obj);
};

#endif // IMPWINDOW_H
