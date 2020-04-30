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

class MainWindow : public QWidget{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow()=default;

private:
    QVBoxLayout *mainLayout;
    QHBoxLayout *itemLayout;
    QVBoxLayout *menuLayout;
    QVBoxLayout *listLayout;
    QHBoxLayout *buttonListLayout;

    void addMainItems();

    void addButtons();

    void addList();

    void setWindowStyle();

};

#endif // MAINWINDOW_H
