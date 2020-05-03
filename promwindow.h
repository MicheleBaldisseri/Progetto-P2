#ifndef PROMWINDOW_H
#define PROMWINDOW_H

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

class PromWindow : public QDialog
{
    Q_OBJECT

public:
    explicit PromWindow(QWidget *parent = 0);
    ~PromWindow();

private slots:

private:
    QDialogButtonBox *buttonBox;
    QVBoxLayout *mainLayout;
    QGroupBox *formGroupBox;
    //QTextEdit *smallEditor;
    QTextEdit *bigEditor;
   // QLabel *labels[NumGridRows];
   // QLineEdit *lineEdits[NumGridRows];
   // QPushButton *buttons[NumButtons];

    void addPromItems();

};

#endif // PROMWINDOW_H


