#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>

#include "task2widget.h"
#include "task3widget.h"


class MainWindow : public QWidget
{
    Q_OBJECT

    QVBoxLayout* vLayout;

    Task2Widget* task2widget;
    Task3Widget* task3widget;


public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
};
#endif // MAINWINDOW_H
