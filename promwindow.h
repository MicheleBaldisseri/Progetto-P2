#ifndef PROMWINDOW_H
#define PROMWINDOW_H

#include <QDialog>
#include <QPlainTextEdit>
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
#include <QColor>
#include <QMessageBox>
#include "datievento.h"

class PromWindow : public QDialog
{
    Q_OBJECT
public:
    explicit PromWindow(QWidget *parent, const QDate& selDate, DatiEvento* e = nullptr);
    ~PromWindow();
public slots:
    void creaEvento();
signals:
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

    void addPromItems();
    void setForm(DatiEvento* obj);
};

#endif // PROMWINDOW_H


