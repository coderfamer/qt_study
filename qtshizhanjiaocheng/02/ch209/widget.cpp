#include "widget.h"
#include "ui_widget.h"
#include <QDebug>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    init();
    connect(ui->treeWidget, SIGNAL(itemChanged(QTreeWidgetItem*,int)), this, SLOT(treeItemChanged(QTreeWidgetItem*,int)) );
}

Widget::~Widget()
{
    delete ui;
}

void Widget::init()
{
    ui->treeWidget->clear();
    //第一个分组
    QTreeWidgetItem *group1 = new QTreeWidgetItem(ui->treeWidget);
    group1->setText(0, "group1");
    group1->setFlags(Qt::ItemIsUserCheckable|Qt::ItemIsEnabled|Qt::ItemIsSelectable);
    group1->setCheckState(0, Qt::Unchecked);

    QTreeWidgetItem *subItem1  = new QTreeWidgetItem(group1);
    subItem1->setFlags(Qt::ItemIsUserCheckable|Qt::ItemIsEnabled|Qt::ItemIsSelectable);
    subItem1->setText(0, "subItem1");
    subItem1->setCheckState(0, Qt::Unchecked);
    QTreeWidgetItem *subItem2  = new QTreeWidgetItem(group1);
    subItem2->setFlags(Qt::ItemIsUserCheckable|Qt::ItemIsEnabled|Qt::ItemIsSelectable);
    subItem2->setText(0, "subItem2");
    subItem2->setCheckState(0, Qt::Unchecked);
    QTreeWidgetItem *subItem3  = new QTreeWidgetItem(group1);
    subItem3->setFlags(Qt::ItemIsUserCheckable|Qt::ItemIsEnabled|Qt::ItemIsSelectable);
    subItem3->setText(0, "subItem3");
    subItem3->setCheckState(0, Qt::Unchecked);
    /*
     * |Qt::ItemIsEnabled  用户可操作
    */
    QTreeWidgetItem *subItem4  = new QTreeWidgetItem(group1);
    subItem4->setFlags(Qt::ItemIsUserCheckable|Qt::ItemIsEnabled|Qt::ItemIsSelectable);
    subItem4->setText(0, "subItem4");
    subItem4->setCheckState(0, Qt::Unchecked);//设置check框

    //第二个分组
    QTreeWidgetItem *group2 = new QTreeWidgetItem(ui->treeWidget);
    group2->setText(0, "group2");
    group2->setFlags(Qt::ItemIsUserCheckable|Qt::ItemIsEnabled|Qt::ItemIsSelectable);
    group2->setCheckState(0, Qt::Unchecked);

    QTreeWidgetItem *subItem21  = new QTreeWidgetItem(group2);
    subItem21->setFlags(Qt::ItemIsUserCheckable|Qt::ItemIsEnabled|Qt::ItemIsSelectable);
    subItem21->setText(0, "subItem21");
    subItem21->setCheckState(0, Qt::Unchecked);
    QTreeWidgetItem *subItem22  = new QTreeWidgetItem(group2);
    subItem22->setFlags(Qt::ItemIsUserCheckable|Qt::ItemIsEnabled|Qt::ItemIsSelectable);
    subItem22->setText(0, "subItem22");
    subItem22->setCheckState(0, Qt::Unchecked);
    QTreeWidgetItem *subItem23  = new QTreeWidgetItem(group2);
    subItem23->setFlags(Qt::ItemIsUserCheckable|Qt::ItemIsEnabled|Qt::ItemIsSelectable);
    subItem23->setText(0, "subItem23");
    subItem23->setCheckState(0, Qt::Unchecked);
    QTreeWidgetItem *subItem24  = new QTreeWidgetItem(group2);
    subItem24->setFlags(Qt::ItemIsUserCheckable|Qt::ItemIsEnabled|Qt::ItemIsSelectable);
    subItem24->setText(0, "subItem24");
    subItem24->setCheckState(0, Qt::Unchecked);
}

void Widget::treeItemChanged(QTreeWidgetItem *item, int column)
{
    QString itemText = item->text(0);
    qDebug() << itemText;
    //选中时
    if (Qt::Checked == item->checkState(0))
    {
        QTreeWidgetItem *parent = item->parent();
        int count = item->childCount();
        qDebug() << count;
        if (count > 0)
        {
            for (int i=0; i<count; i++)
            {
                //子节点也选中
                item->child(i)->setCheckState(0, Qt::Checked);
            }
        }
        else
        {
            updateParentItem(item);
        }
    }
    else if (Qt::Unchecked == item->checkState(0))
    {
        int count = item->childCount();
        if (count > 0)
        {
            for (int i=0; i<count; i++)
            {
                item->child(i)->setCheckState(0, Qt::Unchecked);
            }
        }
        else
        {
            updateParentItem(item);
        }
    }
}


void Widget::updateParentItem(QTreeWidgetItem *item)
{
    QTreeWidgetItem *parent = item->parent();
    if (parent == NULL)
    {
        return;
    }

    //选中的子节点个数
    int  selectedCount = 0;
    int childCount = parent->childCount();
    for (int i=0; i<childCount; i++)
    {
        QTreeWidgetItem *childItem = parent->child(i);
        if (childItem->checkState(0) == Qt::Checked)
        {
            selectedCount++;
        }
    }
    if (selectedCount <= 0)
    {
        //选中状态
        parent->setCheckState(0, Qt::Unchecked);
    }
    else if (selectedCount > 0 && selectedCount < childCount)
    {
        parent->setCheckState(0, Qt::PartiallyChecked);
    }
    else if (selectedCount == childCount)
    {
        parent->setCheckState(0, Qt::Checked);
    }
}
