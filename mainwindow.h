#ifndef MAINWINDOW_H
#define MAINWINDOW_H

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
#include <QTimer>
#include <promwindow.h>
#include <appunwindow.h>
#include <impwindow.h>
#include <QToolButton>
#include <QMenu>

class MainWindow : public QWidget{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow()=default;

public slots:
    void showTime();
    void openPromWindow();
    void openAppunWindow();
    void openImpWindow();

private:
    QVBoxLayout *mainLayout;
    QHBoxLayout *itemLayout;
    QVBoxLayout *menuLayout;
    QVBoxLayout *listLayout;
    QHBoxLayout *buttonListLayout;

    PromWindow* promW;
    AppunWindow* appunW;
    ImpWindow* impW;

    void addMainItems();

    void addButtons();

    void addList();

    void setWindowStyle();

};

#endif // MAINWINDOW_H
