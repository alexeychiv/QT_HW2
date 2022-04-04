#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent)
{
    int width = 640;
    int height = 480;

    QRect winSize;
    winSize.setSize({width, height});
    setGeometry(winSize);

    vLayout = new QVBoxLayout(this);

    task2widget = new Task2Widget(this, width - 25, height / 2 - 20);
    task3widget = new Task3Widget(this, width - 25, height / 2 - 20);

    vLayout->addWidget(task2widget);
    vLayout->addWidget(task3widget);

    setLayout(vLayout);
}

MainWindow::~MainWindow()
{
}

