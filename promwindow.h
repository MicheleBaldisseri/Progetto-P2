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
    explicit PromWindow(QWidget *parent, const QDate& selDate);
    ~PromWindow();
public slots:
    void creaEvento();
signals:
    void eventoInserito(DatiEvento*);
private:

    QDate date;
    QComboBox* colorChoise;
    QLineEdit* title;
    QTimeEdit* setTime;
    QDialogButtonBox *buttonBox;
    QVBoxLayout *mainLayout;
    QGroupBox *formGroupBox;
    QPlainTextEdit *bigEditor;

    void addPromItems();
};

#endif // PROMWINDOW_H


