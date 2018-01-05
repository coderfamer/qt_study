#ifndef IMGPROCESSOR_H
#define IMGPROCESSOR_H

#include <QMainWindow>
#include <QLabel>
#include <QMenu>
#include <QString>
#include <QTextCharFormat>
#include <QImage>
#include <QAction>
#include <QToolBar>
#include <QFontComboBox>
#include <QToolButton>
#include <QActionGroup>

#include "showwidget.h"

class ImgProcessor : public QMainWindow
{
    Q_OBJECT

public:
    ImgProcessor(QWidget *parent = 0);
    ~ImgProcessor();

    void createActions();
    void createMenus();
    void createToolBars();

    void loadFile(QString filename);
    void mergeFormat(QTextCharFormat);

protected slots:
    void showNewFile();
    void showOpenFile();
    void showPrintText();
    void ShowZoomIn();
    void ShowZoomOut();
    void ShowRotate90();//旋转功能
    void ShowRotate180();
    void ShowRotate270();
    void ShowMirrorVertical();
    void ShowMirrorHorizontal();
    void ShowFontComboBox(QString comboStr);
    void ShowSizeSpinBox(QString spinValue);
    void ShowBoldBtn();
    void ShowItalicBtn();
    void ShowUnderlineBtn();
    void ShowColorBtn();
    void ShowCurrentFormatChanged(const QTextCharFormat &fmt);
    void ShowList(int index);
    void ShowAlignment(QAction *act);
    void ShowCursorPositionChanged();

private:
    QMenu *fileMenu;
    QMenu *zoomMenu;
    QMenu *rotateMenu;
    QMenu *mirrorMenu;

    QImage img;
    QString fileName;
    ShowWidget *showWidget;

    QAction *openFileAction;
    QAction *newFileAction;
    QAction *printImageAction;
    QAction *printTextAction;
    QAction *exitAction;
    QAction *copyAction;
    QAction *cutAction;
    QAction *pasteAction;
    QAction *aboutAction;
    QAction *zoomInAction;
    QAction *zoomOutAction;

    QAction *rotate90Action;
    QAction *rotate180Action;
    QAction *rotate270Action;

    QAction *mirrorVerticalAction;
    QAction *mirrorHorizontalAction;

    QAction *undoAction;
    QAction *redoAction;

    QLabel *fontLabel1;
    QFontComboBox *fontComboBox;
    QLabel *fontLabel2;
    QComboBox *sizeComboBox;
    QToolButton *boldBtn;
    QToolButton *italicBtn;
    QToolButton *underlineBtn;
    QToolButton *colorBtn;

    QLabel *listLabel;
    QComboBox *listComboBox;
    QActionGroup *actGrp;
    QAction *leftAction;
    QAction *rightAction;
    QAction *centerAction;
    QAction *justifyAction;


    QToolBar *fileTool;
    QToolBar *zoomTool;
    QToolBar *rotateTool;
    QToolBar *mirrorTool;

    QToolBar *doToolBar;
    QToolBar *fontToolBar;
    QToolBar *listToolBar;


};

#endif // IMGPROCESSOR_H
