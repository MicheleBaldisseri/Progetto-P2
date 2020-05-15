#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <iostream>
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
#include <compwindow.h>
#include <QToolButton>
#include <QMenu>
#include <QListWidget>
using std::string;

class Controller;

class MainWindow : public QWidget{
    Q_OBJECT

public:
    MainWindow(Controller* controller, QWidget *parent = nullptr);
    ~MainWindow()=default;

    void addEventList(string text,int color);
    void updateList();
    void clearList();

public slots:
    void showTime();
    void inserisciEvento(int type);

private:
    Controller* controller;

    QVBoxLayout *mainLayout;
    QHBoxLayout *itemLayout;
    QVBoxLayout *menuLayout;
    QVBoxLayout *listLayout;
    QHBoxLayout *buttonListLayout;

    PromWindow* promW;
    AppunWindow* appunW;
    ImpWindow* impW;
    CompWindow* compW;

    void addMainItems();
    void addButtons();
    void addList();
    void setWindowStyle();

};

#endif // MAINWINDOW_H
