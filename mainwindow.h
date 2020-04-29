#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QCalendarWidget>
#include <QListView>
#include <QFrame>

class MainWindow : public QWidget{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow()=default;

private:
    QVBoxLayout *mainLayout;
    QHBoxLayout *itemLayout;
    QVBoxLayout *buttonLayout;

    void addMainItems();

    void addButtons();

    void setWindowStyle();

};

#endif // MAINWINDOW_H
