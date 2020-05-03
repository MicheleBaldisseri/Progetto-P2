#ifndef COMPWINDOW_H
#define COMPWINDOW_H

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

class CompWindow : public QDialog
{
    Q_OBJECT

public:
    explicit CompWindow(QWidget *parent = 0);
    ~CompWindow();

private slots:

private:
    QDialogButtonBox *buttonBox;
    QVBoxLayout *mainLayout;
    QGroupBox *formGroupBox;
    void addCompItems();

};
#endif // COMPWINDOW_H
