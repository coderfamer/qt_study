#include "dockwindows.h"
#include <QTextEdit>
#include <QDockWidget>
DockWindows::DockWindows(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowTitle(tr("DockWindows"));
    QTextEdit *te = new QTextEdit(this);
    te->setText("Main Window");
    te->setAlignment(Qt::AlignCenter);
    setCentralWidget(te);

    //停靠窗口
    /*
     * setFeatures() 方法设置停靠窗体的属性
     * QDockWidget::DockWidgetClosable：停靠窗体可关闭
     * QDockWidget::DockWidgetMovable：停靠窗体可移动
     * QDockWidget::DockWidgetFloatable：停靠窗体可浮动
     * QDockWidget::AllDockWidgetFeatures：拥有停靠窗体的所有特性
     * QDockWidget::NoDockWidgetFeatures：不可移动，不可关闭，不可浮动
    */
    /*
     * setAllowedAreas()方法设置窗体的可停靠区域
     * void setAllowedAreas(Qt::DockWidgetAreas areas)
     * Qt::LeftDockWidgetArea：在主窗口的左侧停靠
     * Qt::RightDockWidgetArea：右侧
     * Qt::TopDockWidgetArea：顶端
     * Qt::BottomDockWidgetArea：底部
     * Qt::AllDockWidgetAreas
    */
    QDockWidget *dock = new QDockWidget(tr("DockWindow1") ,this);
    dock->setFeatures(QDockWidget::DockWidgetMovable);//可移动
    dock->setAllowedAreas(Qt::LeftDockWidgetArea|Qt::RightDockWidgetArea);
    QTextEdit *tel = new QTextEdit();
    tel->setText(tr("dock widget can be moved"));
    dock->setWidget(tel);
    addDockWidget(Qt::RightDockWidgetArea, dock);

    dock = new QDockWidget(tr("dockWindow2"), this);
    dock->setFeatures(QDockWidget::DockWidgetClosable|QDockWidget::DockWidgetFloatable);
    QTextEdit *te2 = new QTextEdit();
    te2->setText(tr("dock widget can be detached an floated and closed"));
    dock->setWidget(te2);
    addDockWidget(Qt::RightDockWidgetArea, dock);

    dock = new QDockWidget(tr("dockWindow3"), this);
    dock->setFeatures(QDockWidget::AllDockWidgetFeatures);
    QTextEdit *te3 = new QTextEdit();
    te3->setText(tr("all reatures"));
    dock->setWidget(te3);
    addDockWidget(Qt::RightDockWidgetArea, dock);

    dock = new QDockWidget(tr("dockWindow4"), this);
    dock->setFeatures(QDockWidget::NoDockWidgetFeatures);
    QTextEdit *te4 = new QTextEdit();
    te4->setText(tr("no features"));
    dock->setWidget(te4);
    addDockWidget(Qt::RightDockWidgetArea, dock);

    dock = new QDockWidget(tr("dockWindow5"), this);
    dock->setFeatures(QDockWidget::DockWidgetVerticalTitleBar);
    QTextEdit *te5 = new QTextEdit();
    te5->setText(tr("no features"));
    dock->setWidget(te5);
    addDockWidget(Qt::RightDockWidgetArea, dock);


}

DockWindows::~DockWindows()
{

}
