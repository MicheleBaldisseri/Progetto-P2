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
#include <QTextEdit>
#include <QMenuBar>
#include <QPushButton>
#include <QTimeEdit>

class AppunWindow : public QDialog
{
    Q_OBJECT

public:
    explicit AppunWindow(QWidget *parent = 0);
    ~AppunWindow();

private:
    void createFormGroupBox();
    QGroupBox *formGroupBox;
    QDialogButtonBox *buttonBox;
};

#endif // APPUNWINDOWS_H
