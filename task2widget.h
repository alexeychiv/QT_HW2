#ifndef TASK2WIDGET_H
#define TASK2WIDGET_H

#include <QApplication>

#include <QWidget>

#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QFrame>
#include <QLabel>
#include <QLineEdit>
#include <QCheckBox>
#include <QPushButton>
#include <QListView>
#include <QStandardItemModel>


class Task2Widget : public QWidget
{
    Q_OBJECT

    QFrame* frame;
    QVBoxLayout* vLayout;

    QCheckBox* chBoxIconMode;

    QHBoxLayout* hLayoutButtons;
    QLineEdit* lineEditNewLang;
    QPushButton* btnAdd;
    QPushButton* btnDelete;
    QPushButton* btnMoveUp;
    QPushButton* btnMoveDn;

    QListView* langListView;
    QStandardItemModel* languageModel;

    void setupUI(int width, int height);
    void fillList();

private slots:
    void on_chBoxIconMode_stateChanged(bool isChecked);

    void on_btnAdd_clicked();
    void on_btnDelete_clicked();
    void on_btnMoveUp_clicked();
    void on_btnMoveDn_clicked();

private:
    void moveItem(QModelIndexList& selectedList, const int shift);

public:
    Task2Widget(QWidget *parent = nullptr, int width = 640, int height = 480);
    ~Task2Widget();

};
#endif // TASK2WIDGET_H
