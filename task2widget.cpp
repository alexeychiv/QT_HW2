#include "task2widget.h"

#include <QString>

//====================================================
//SETUP

void Task2Widget::setupUI(int width, int height)
{
    QRect winSize;
    winSize.setSize({width, height});
    setGeometry(winSize);

    frame = new QFrame(this);
    frame->setGeometry(winSize);
    frame->setFrameStyle(QFrame::Box);

    vLayout = new QVBoxLayout();
    vLayout->addWidget(new QLabel("Task 2:"));

    hLayoutButtons = new QHBoxLayout();

    lineEditNewLang = new QLineEdit;

    btnAdd = new QPushButton("Add");
    btnDelete = new QPushButton("Delete");
    btnMoveUp = new QPushButton("Move Up");
    btnMoveDn = new QPushButton("Move Down");

    hLayoutButtons->addWidget(lineEditNewLang);
    hLayoutButtons->addWidget(btnAdd);
    hLayoutButtons->addWidget(btnDelete);
    hLayoutButtons->addWidget(btnMoveUp);
    hLayoutButtons->addWidget(btnMoveDn);

    vLayout->addLayout(hLayoutButtons);

    chBoxIconMode = new QCheckBox("Icon Mode");
    vLayout->addWidget(chBoxIconMode);

    langListView = new QListView(frame);
    vLayout->addWidget(langListView);

    frame->setLayout(vLayout);

    QObject::connect(chBoxIconMode, &QCheckBox::stateChanged, this, &Task2Widget::on_chBoxIconMode_stateChanged);
    QObject::connect(btnAdd, &QPushButton::clicked, this, &Task2Widget::on_btnAdd_clicked);
    QObject::connect(btnDelete, &QPushButton::clicked, this, &Task2Widget::on_btnDelete_clicked);
    QObject::connect(btnMoveUp, &QPushButton::clicked, this, &Task2Widget::on_btnMoveUp_clicked);
    QObject::connect(btnMoveDn, &QPushButton::clicked, this, &Task2Widget::on_btnMoveDn_clicked);
}

void Task2Widget::fillList()
{
    languageModel = new QStandardItemModel(this);

    languageModel->appendRow(new QStandardItem(QIcon(":/res/res/cpp_icon.png"), "С++"));
    languageModel->appendRow(new QStandardItem(QIcon(":/res/res/python_icon.png"), "Python"));
    languageModel->appendRow(new QStandardItem(QIcon(":/res/res/java_icon.png"), "Java"));
    languageModel->appendRow(new QStandardItem(QIcon(":/res/res/cs_icon.jpg"), "C#"));
    languageModel->appendRow(new QStandardItem(QIcon(":/res/res/php_icon.jpg"), "PHP"));
    languageModel->appendRow(new QStandardItem(QIcon(":/res/res/javaScript_icon.jpg"), "JavaScript"));

    langListView->setModel(languageModel);
    langListView->setDragEnabled(true);

    langListView->setDragDropMode(QAbstractItemView::NoDragDrop);
}

//====================================================
//EVENTS

void Task2Widget::on_chBoxIconMode_stateChanged(bool isChecked)
{
    if (isChecked)
        langListView->setViewMode(QListView::IconMode);
    else
        langListView->setViewMode(QListView::ListMode);
}

void Task2Widget::on_btnAdd_clicked()
{
    QString newLangName = lineEditNewLang->text();
    if (newLangName == "")
        newLangName = "New Language";



    languageModel->insertRow(0, new QStandardItem(
        QIcon(QApplication::style()->standardIcon(QStyle::SP_FileIcon)),
        newLangName)
    );
}

void Task2Widget::on_btnDelete_clicked()
{

    foreach(const QModelIndex &index, langListView->selectionModel()->selectedIndexes())
        languageModel->removeRow(index.row());
}

void Task2Widget::on_btnMoveUp_clicked()
{
    QModelIndexList selectedList = langListView->selectionModel()->selectedIndexes();

    if (selectedList.size() != 1)
        return;
    if (selectedList[0].row() == 0)
        return;

    moveItem(selectedList, -1);
}

void Task2Widget::on_btnMoveDn_clicked()
{
    QModelIndexList selectedList = langListView->selectionModel()->selectedIndexes();

    if (selectedList.size() != 1)
        return;
    if (selectedList[0].row() == languageModel->rowCount() - 1)
        return;

    moveItem(selectedList, +1);
}

void Task2Widget::moveItem(QModelIndexList& selectedList, const int shift)
{
    int newRowIndex = selectedList[0].row() + shift;
    QList<QStandardItem *> items = languageModel->takeRow(selectedList[0].row());
    languageModel->insertRow(newRowIndex, items);

    langListView->setCurrentIndex(languageModel->index(newRowIndex, 0));
}

//====================================================
//CONSTRUCTOR

Task2Widget::Task2Widget(QWidget *parent, int width, int height)
    : QWidget(parent)
{
    setupUI(width, height);
    fillList();
}

//====================================================
//DESTRUCTOR

Task2Widget::~Task2Widget()
{
}

