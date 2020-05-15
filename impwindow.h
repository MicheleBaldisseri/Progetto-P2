#ifndef IMPWINDOW_H
#define IMPWINDOW_H

#include <QDialog>
#include <QTextEdit>
#include <QWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QCalendarWidget>
#include <QListView>
#include <QFrame>
#include <QPushButton>
#include <QLabel>
#include <QDateTime>
#include <QFile>
#include <QComboBox>
#include <QGroupBox>
#include <QDialogButtonBox>
#include <QFormLayout>
#include <QLineEdit>
#include <QTimeEdit>
#include <QCheckBox>
#include <QDateTimeEdit>
#include <QSpinBox>
#include "datievento.h"
#include <QColor>

class ImpWindow : public QDialog
{
    Q_OBJECT

public:
    explicit ImpWindow(QWidget *parent = 0);
    ~ImpWindow();

public slots:
    void inserisciManualmente(bool checked);
    void creaEvento();
signals:
    void eventoInserito(DatiEvento*);
private:
    QDialogButtonBox *buttonBox;
    QVBoxLayout *mainLayout;
    QGroupBox *formGroupBox;
    QGroupBox *RicorrenzaGroupBox;
    void addImpItems();

    QDateEdit* n1, *n2, *n3;
    QComboBox* ricChoise,* colorChoise;
    QSpinBox* intOcc, *intGiorni;
    QLineEdit* title;
    QTimeEdit* setTimeBegin, *setTimeEnd;
};

#endif // IMPWINDOW_H
