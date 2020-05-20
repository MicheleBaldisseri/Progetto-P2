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

class CompWindow : public QDialog
{
    Q_OBJECT
public:
    explicit CompWindow(QWidget *parent, const QDate& selDate);
    ~CompWindow();
public slots:
    void creaEvento();
signals:
    void eventoInserito(DatiEvento*);
private:
    QDate date;
    QComboBox* colorChoise;
    QLineEdit* title;
    QSpinBox* setYear;
    QDialogButtonBox *buttonBox;
    QVBoxLayout *mainLayout;
    QGroupBox *formGroupBox;

    void addCompItems();
};
#endif // COMPWINDOW_H
