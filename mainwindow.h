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
#include <QIcon>
#include <QTimer>
#include <promwindow.h>
#include <appunwindow.h>
#include <impwindow.h>
#include <compwindow.h>
#include <QToolButton>
#include <QMenu>
#include <QListWidget>
#include <QMessageBox>
#include "datievento.h"
using std::string;

class Controller;

class MainWindow : public QWidget{
    Q_OBJECT

public:
    MainWindow(Controller* controller, QWidget *parent = nullptr);
    ~MainWindow()=default;

    //aggiunge un evento alla lista della vista
    void addEventList(const string& text, const int& color);
    //aggiorna la lista della vista
    void updateList();
    //pulisce la lista della vista
    void clearList();
    //mostra un messaggio
    void showMessage(const bool& done, QString title, QString messagge);
    //richiama le finestre di inserimento, ma con i dati dell'evento per modificare
    void initializeModifica(DatiEvento* e);
    int getPos();
public slots:
    //mostra la data e ora (richiamato da un timer)
    void showTime();
    //richiama le finestre di inserimento in base al tasto usato
    void inserisciEvento(int type);
    //prende la posizione dell'evento selezionato e lo passa al controller per eliminarlo
    void eliminaEvento();
    //prende la posizione dell'evento selezionato e lo passa al controller per modificarlo
    void modificaEvento();
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
