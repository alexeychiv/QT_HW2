#include "task3widget.h"

//====================================================
//SETUP

void Task3Widget::setupUI(int width, int height)
{
    QRect winSize;
    winSize.setSize({width, height});
    setGeometry(winSize);

    frame = new QFrame(this);
    frame->setGeometry(winSize);
    frame->setFrameStyle(QFrame::Box);

    vLayout = new QVBoxLayout();
    vLayout->addWidget(new QLabel("Task 3:"));


    btnPaintSelected = new QPushButton("Paint Selected");

    vLayout->addWidget(btnPaintSelected);

    compsTableView = new QTableView(frame);
    compsTableView->setSelectionMode(QAbstractItemView::ExtendedSelection);
    compsTableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    vLayout->addWidget(compsTableView);

    frame->setLayout(vLayout);

    QObject::connect(btnPaintSelected, &QPushButton::clicked, this, &Task3Widget::on_btnPaintSelected_clicked);
}

void Task3Widget::fillTable()
{
    compsModel = new QStandardItemModel(this);
    compsTableView->setModel(compsModel);

    compsModel->setColumnCount(4);
    QStringList header = {"Num", "Comp name", "IP", "MAC"};
    compsModel->setHorizontalHeaderLabels(header);

    compsModel->appendRow(createCompRow("1", "Server", "192.168.1.1", "00:AB:CD:EF:11:22"));
    compsModel->appendRow(createCompRow("2", "WS1", "192.168.1.21", "10:TY:CD:WP:35:38"));
    compsModel->appendRow(createCompRow("3", "WS2", "192.168.1.22", "01:WJ:FG:SL:14:32"));
    compsModel->appendRow(createCompRow("4", "WS3", "192.168.1.23", "11:FO:CD:OG:40:78"));
}

QList<QStandardItem *> Task3Widget::createCompRow(QString num, QString name, QString ip, QString mac)
{
    QList<QStandardItem*> comp;

    QStandardItem* compNum = new QStandardItem(num);
    QStandardItem* compName = new QStandardItem(name);
    QStandardItem* compIP = new QStandardItem(ip);
    QStandardItem* compMAC = new QStandardItem(mac);

    comp.append(compNum);
    comp.append(compName);
    comp.append(compIP);
    comp.append(compMAC);

    return comp;
}

//====================================================
//EVENTS

void Task3Widget::on_btnPaintSelected_clicked()
{
    QModelIndexList selectedList = compsTableView->selectionModel()->selectedIndexes();

    if (selectedList.size() == 0)
        return;

    foreach(const QModelIndex &index, selectedList)
    {
        compsModel->item(index.row(), index.column())->setData(QColor(Qt::green), Qt::BackgroundRole);
    }
}

//====================================================
//CONSTRUCTOR

Task3Widget::Task3Widget(QWidget *parent, int width, int height)
    : QWidget(parent)
{
    setupUI(width, height);
    fillTable();
}

//====================================================
//DESTRUCTOR

Task3Widget::~Task3Widget()
{
}

