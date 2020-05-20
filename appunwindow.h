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
    explicit AppunWindow(QWidget *parent, const QDate& selDate);
    ~AppunWindow();
public slots:
    void creaEvento();
signals:
    void eventoInserito(DatiEvento*);
private:

    QDate date;
    QComboBox* colorChoise;
    QLineEdit* title, * location;
    QTimeEdit* setTimeBegin,* setTimeEnd;
    QGroupBox *formGroupBox;
    QDialogButtonBox *buttonBox;

    void createFormGroupBox();
};

#endif // APPUNWINDOWS_H
