#ifndef TASK3WIDGET_H
#define TASK3WIDGET_H

#include <QApplication>

#include <QWidget>

#include <QVBoxLayout>
#include <QFrame>
#include <QLabel>
#include <QPushButton>
#include <QTableView>
#include <QStandardItemModel>


class Task3Widget : public QWidget
{
    Q_OBJECT

    QFrame* frame;
    QVBoxLayout* vLayout;

    QPushButton* btnPaintSelected;

    QTableView* compsTableView;
    QStandardItemModel* compsModel;

    void setupUI(int width, int height);
    void fillTable();

    QList<QStandardItem*> createCompRow(QString num, QString name, QString ip, QString mac);

private slots:
    void on_btnPaintSelected_clicked();



public:
    Task3Widget(QWidget *parent = nullptr, int width = 640, int height = 480);
    ~Task3Widget();
};
#endif // TASK3WIDGET_H
