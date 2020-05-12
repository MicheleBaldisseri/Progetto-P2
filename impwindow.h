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

class ImpWindow : public QDialog
{
    Q_OBJECT

public:
    explicit ImpWindow(QWidget *parent = 0);
    ~ImpWindow();

public slots:

    void inserisciManualmente(bool checked);

private:
    QDialogButtonBox *buttonBox;
    QVBoxLayout *mainLayout;
    QGroupBox *formGroupBox;
    QGroupBox *RicorrenzaGroupBox;
    void addImpItems();

    QDateEdit* n1;
    QDateEdit* n2;
    QDateEdit* n3;
    QComboBox* ricChoise;
    QSpinBox* intOcc;
    QSpinBox* intGiorni;

};

#endif // IMPWINDOW_H
