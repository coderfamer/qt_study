#ifndef LBASEDIALOG_H
#define LBASEDIALOG_H
#include "lglobal.h"

#include <QDialog>
class  LBaseDialog : public QDialog
{
    Q_OBJECT
    L_DECLARE_PRIVATE(LBaseDialog)
    public:
        enum LWindowFlag {
                 ToolClose	= 0x00000001,
                 ToolMin	= 0x00000002,
                 ToolMax	= 0x00000004,
                 ToolSkin	= 0x00000008,
                 ToolSet	= 0x00000010,
                 ToolIcon	= 0x00000020,
                 ToolTitle	= 0x00000040
    };

    explicit LBaseDialog(QWidget *iParent = 0);
    ~LBaseDialog();

    //void setTaskBarIconVisible(bool iVisible);
    void setIcon(const QIcon &iIcon);
    void setTitle(const QString &iTitle);
    void setMoveAble(bool isMove = true);

    virtual void createTitleBar(QWidget *iParent, uint iFlag, const QString &iTitle = "", int iTitleHeight = 30);
    virtual void mousePressEvent(QMouseEvent *e);
    virtual void mouseMoveEvent(QMouseEvent *);
    virtual void mouseReleaseEvent(QMouseEvent *);
    virtual void resizeEvent(QResizeEvent *event);

protected slots:
    virtual void doToolButtonMin();
    virtual void doToolButtonMax();
//    virtual void doToolButtonNor();
    virtual void doToolButtonClose();
    virtual void doToolButtonSet();
    virtual void doToolButtonSkin();

//protected:
//    virtual void changeEvent(QEvent *);
//    virtual void paintEvent(QPaintEvent *);
};

#endif // LBASEDIALOG_H
