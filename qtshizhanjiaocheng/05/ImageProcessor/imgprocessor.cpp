#include "imgprocessor.h"
#include <QPixmap>
#include <QMenuBar>
#include <QKeySequence>
#include <QApplication>
#include <QFileDialog>
#include <QFile>
#include <QTextStream>
#include <QtPrintSupport/QPrinter>
#include <QtPrintSupport/QPrintDialog>
#include <QTextDocument>
#include <QMatrix>
#include <QFontDatabase>
#include <QTextCharFormat>
#include <QColorDialog>
#include <QColor>
#include <QTextListFormat>
#include <QTextCursor>
#include <QTextBlockFormat>
#include <QTextList>

ImgProcessor::ImgProcessor(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowTitle(tr("Easy Word"));

    showWidget = new ShowWidget(this);
    //Sets the given widget to be the main window's central widget.
    setCentralWidget(showWidget);


    //在工具栏上嵌入控件
    //排序
    listLabel = new QLabel(tr("排序"));
    listComboBox = new QComboBox;
    listComboBox->addItem("Standard");
    listComboBox->addItem("QTextListFormat::ListDisc");
    listComboBox->addItem("QTextListFormat::ListCircle");
    listComboBox->addItem("QTextListFormat::ListSquare");
    listComboBox->addItem("QTextListFormat::ListDecimal");
    listComboBox->addItem("QTextListFormat::ListLowerAlpha");
    listComboBox->addItem("QTextListFormat::ListUpperAlpha");
    listComboBox->addItem("QTextListFormat::ListLowerRoman");
    listComboBox->addItem("QTextListFormat::ListUpperRoman");

    //设置字体
    fontLabel1 = new QLabel(tr("字体:"));
    fontComboBox = new QFontComboBox;
    fontComboBox->setFontFilters(QFontComboBox::ScalableFonts);

    fontLabel2 = new QLabel(tr("字号:"));
    sizeComboBox = new QComboBox;
    QFontDatabase db;
    foreach (int size, db.standardSizes()) {
        sizeComboBox->addItem(QString::number(size));
    }

    boldBtn = new QToolButton;
    boldBtn->setIcon(QIcon(":/images/bold.png"));
    boldBtn->setCheckable(true);
    italicBtn = new QToolButton;
    italicBtn->setIcon(QIcon(":/images/italic.png"));
    italicBtn->setCheckable(true);

    underlineBtn = new QToolButton;
    underlineBtn->setIcon(QIcon(":/images/Underline.png"));
    underlineBtn->setCheckable(true);

    colorBtn = new QToolButton;
    colorBtn->setIcon(QIcon(":/images/color.png"));
    colorBtn->setCheckable(true);

    createActions();
    createMenus();
    createToolBars();

    if (img.load(":/images/image.png"))
    {
         /*
        *Copies pixmap into the clipboard.
        * Note that this is slower than setImage() because it needs to convert the QPixmap to a QImage first.
        */
        showWidget->imageLabel->setPixmap(QPixmap::fromImage(img));
    }

    connect(fontComboBox, SIGNAL(activated(QString)),
            this, SLOT(ShowFontComboBox(QString)) );
    connect(sizeComboBox, SIGNAL(activated(QString)),
            this, SLOT(ShowSizeSpinBox(QString)) );
    connect(boldBtn, SIGNAL(clicked(bool)),this, SLOT(ShowBoldBtn()) );
    connect(italicBtn, SIGNAL(clicked(bool)),this, SLOT(ShowItalicBtn()) );
    connect(underlineBtn, SIGNAL(clicked(bool)),this, SLOT(ShowUnderlineBtn()) );
    connect(colorBtn, SIGNAL(clicked(bool)),this, SLOT(ShowColorBtn()) );
    connect(showWidget->text, SIGNAL(currentCharFormatChanged(QTextCharFormat&)),
            this, SLOT(ShowCurrentFormatChanged(QTextCharFormat&)));
    connect(listComboBox, SIGNAL(activated(int)), this, SLOT(ShowList(int)) );
    connect(showWidget->text->document(), SIGNAL(undoAvailable(bool)),
            undoAction, SLOT(setEnabled(bool)));
    connect(showWidget->text->document(), SIGNAL(redoAvailable(bool)),
            redoAction, SLOT(setEnabled(bool)) );
    connect(showWidget->text, SIGNAL(cursorPositionChanged()),
            this, SLOT(ShowCursorPositionChanged()) );
}

ImgProcessor::~ImgProcessor()
{

}

void ImgProcessor::createActions()
{
    //打开动作
    //在创建打开文件动作的同时，指定了此动作使用的图标，名称及父窗口
    openFileAction = new QAction(QIcon(":/images/open.png"), tr("&Open..."), this);
    //一下几种方式全部都可以设置组合键
    //openFileAction->setShortcut(tr("Ctrl+o"));
    //openFileAction->setShortcut(QKeySequence::Open);
    //openFileAction->setShortcut(QKeySequence(tr("Ctrl+o")));
    openFileAction->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_O));
    openFileAction->setStatusTip(tr("打开一个文件"));
    connect(openFileAction, SIGNAL(triggered(bool)), this, SLOT(showOpenFile()) );

    //新建动作
    //The QIcon class provides scalable icons in different modes and states.
    newFileAction = new QAction(QIcon(":/images/new.png"), tr("&New..."), this);
    newFileAction->setShortcut(QKeySequence::New);
    newFileAction->setStatusTip(tr("新建一个文件"));
    connect(newFileAction, SIGNAL(triggered(bool)), this, SLOT(showNewFile()) );

    //退出动作
    exitAction = new QAction(tr("&Exit"), this);
    exitAction->setShortcut(tr("Ctrl+Q"));
    exitAction->setStatusTip(tr("退出程序"));
    connect(exitAction, SIGNAL(triggered(bool)), this, SLOT(close()) );
//    QAction *printImageAction;
    printImageAction = new QAction(QIcon(":/images/printImage.png"), tr("printImage"), this);
    printImageAction->setStatusTip(tr("print a image"));
//    QAction *printTextAction;
    printTextAction = new QAction(QIcon(":/images/printText.png"), tr("printTextr"), this);
    printTextAction->setStatusTip(tr("print a Text"));
    connect(printTextAction, SIGNAL(triggered(bool)), this, SLOT(showPrintText()) );

    //复制
    copyAction = new QAction(QIcon(":/images/copy.png"), tr("&copy..."), this);
    copyAction->setShortcut(QKeySequence::Copy);
    copyAction->setStatusTip(tr("复制文件"));
    connect(copyAction, SIGNAL(triggered(bool)), showWidget->text, SLOT(copy()) );

    cutAction = new QAction(QIcon(":/images/cut.png"), tr("&cut..."), this);
    cutAction->setShortcut(QKeySequence::Cut);
    cutAction->setStatusTip(tr("剪切文件"));
    connect(cutAction, SIGNAL(triggered(bool)), showWidget->text, SLOT(cut()) );

    pasteAction = new QAction(QIcon(":/images/paste.png"), tr("&paste..."), this);
    pasteAction->setShortcut(QKeySequence::Paste);
    pasteAction->setStatusTip(tr("粘贴文件"));
    connect(pasteAction, SIGNAL(triggered(bool)), showWidget->text, SLOT(paste()) );

    aboutAction = new QAction(tr("&About"), this);
    connect(aboutAction, SIGNAL(triggered(bool)), this, SLOT(QApplication::aboutQt()) );

//    QAction *zoomInAction;
    zoomInAction = new QAction(QIcon(":/images/zoomin.png"), tr("Zoom In"), this);
    zoomInAction->setStatusTip(tr("zoom in a image"));
    connect(zoomInAction, SIGNAL(triggered(bool)), this, SLOT(ShowZoomIn()) );

//    QAction *zoomOutAction;
    zoomOutAction = new QAction(QIcon(":/images/zoomout.png"), tr("Zoom Out"), this);
    zoomOutAction->setStatusTip(tr("zoom out a image"));
    connect(zoomOutAction, SIGNAL(triggered(bool)), this, SLOT(ShowZoomOut()) );


//    QAction *rotate90Action;
    rotate90Action = new QAction(QIcon(":/images/rotate90.png"), tr("rotate 90"), this);
    rotate90Action->setStatusTip(tr("rotate 90"));
    connect(rotate90Action, SIGNAL(triggered(bool)), this, SLOT(ShowRotate90()) );

//    QAction *rotate180Action;
    rotate180Action = new QAction(QIcon(":/images/rotate180.png"), tr("rotate 180"), this);
    rotate180Action->setStatusTip(tr("rotate 180"));
    connect(rotate180Action, SIGNAL(triggered(bool)), this, SLOT(ShowRotate180()) );

//    QAction *rotate270Action;
    rotate270Action = new QAction(QIcon(":/images/rotate270.png"), tr("rotate 270"), this);
    rotate270Action->setStatusTip(tr("rotate 270"));
    connect(rotate270Action, SIGNAL(triggered(bool)), this, SLOT(ShowRotate270()) );

    //实现图象镜像的动作
//    QAction *mirrorVerticalAction;
    mirrorVerticalAction = new QAction(QIcon(":/images/mirrorVertical.png"), tr("mirrorVertical"), this);
    connect(mirrorVerticalAction, SIGNAL(triggered(bool)), this, SLOT(ShowMirrorVertical()) );

    //    QAction *mirrorHorizontalAction;
    mirrorHorizontalAction = new QAction(QIcon(":/images/mirrorHorizontal.png"), tr("mirrorHorizontal"), this);
    connect(mirrorHorizontalAction, SIGNAL(triggered(bool)), this, SLOT(ShowMirrorHorizontal()) );

    //撤销和恢复
//    QAction *undoAction;
    undoAction = new QAction(QIcon(":/images/undo.png"), "undo", this);
    connect(undoAction, SIGNAL(triggered(bool)), showWidget->text, SLOT(undo()) );
//    QAction *redoAction;
    redoAction = new QAction(QIcon(":/images/redo.png"), "redo", this);
    connect(redoAction, SIGNAL(triggered(bool)), showWidget->text, SLOT(redo()) );

    //排序：左对齐、右对齐、居中和两端对齐
    actGrp = new QActionGroup(this);

    leftAction = new QAction(QIcon(":/images/left.png"), "左对齐", actGrp);
    leftAction->setCheckable(true);

    rightAction = new QAction(QIcon(":/images/right.png"), "右对齐", actGrp);
    rightAction->setCheckable(true);

    centerAction = new QAction(QIcon(":/images/center.png"), "居中", actGrp);
    centerAction->setCheckable(true);

    justifyAction = new QAction(QIcon(":/images/justify.png"), "两端对齐", actGrp);
    justifyAction->setCheckable(true);

    connect(actGrp, SIGNAL(triggered(QAction*)), this,
            SLOT(ShowAlignment(QAction*)) );
}

void ImgProcessor::createMenus()
{
    //文件菜单
    //直接调用QMainwindow的menuBar()函数即可得到菜单条指针
    fileMenu = menuBar()->addMenu(tr("文件"));
    fileMenu->addAction(openFileAction);
    fileMenu->addAction(newFileAction);
    fileMenu->addAction(printImageAction);
    fileMenu->addAction(printTextAction);
    fileMenu->addSeparator();
    fileMenu->addAction(aboutAction);
    fileMenu->addAction(exitAction);

    zoomMenu = menuBar()->addMenu(tr("编辑"));
    zoomMenu->addAction(copyAction);
    zoomMenu->addAction(cutAction);
    zoomMenu->addAction(pasteAction);
    zoomMenu->addSeparator();
    zoomMenu->addAction(zoomInAction);
    zoomMenu->addAction(zoomOutAction);


    rotateMenu = menuBar()->addMenu(tr("旋转"));
    rotateMenu->addAction(rotate90Action);
    rotateMenu->addAction(rotate180Action);
    rotateMenu->addAction(rotate270Action);

    mirrorMenu = menuBar()->addMenu(tr("翻转"));
    mirrorMenu->addAction(mirrorHorizontalAction);
    mirrorMenu->addAction(mirrorVerticalAction);

}
void ImgProcessor::createToolBars()
{
    //文件工具条
    //fileTool = addToolBar("File");
    fileTool = new QToolBar("file");
    fileTool->addAction(openFileAction);
    fileTool->addAction(newFileAction);
    fileTool->addAction(printImageAction);
    fileTool->addAction(printTextAction);

    //编辑个工具条
    //zoomTool = addToolBar("Edit");
    zoomTool = new QToolBar("Edit");
    zoomTool->addAction(copyAction);
    zoomTool->addAction(cutAction);
    zoomTool->addAction(pasteAction);
    zoomTool->addSeparator();
    zoomTool->addAction(zoomInAction);
    zoomTool->addAction(zoomOutAction);
    //zoomTool->addAction


    //rotateTool = addToolBar("Rotate");
    rotateTool = new QToolBar("Rotate");
    rotateTool->addAction(rotate90Action);
    rotateTool->addAction(rotate180Action);
    rotateTool->addAction(rotate270Action);

    //doToolBar = addToolBar("doEdit");
    doToolBar = new QToolBar("doEdit");
    doToolBar->addAction(undoAction);
    doToolBar->addAction(redoAction);

    //fontToolBar = addToolBar("Font");
    fontToolBar = new QToolBar("Font");
    fontToolBar->addWidget(fontLabel1);
    fontToolBar->addWidget(fontComboBox);
    fontToolBar->addWidget(fontLabel2);
    fontToolBar->addWidget(sizeComboBox);
    fontToolBar->addSeparator();
    fontToolBar->addWidget(boldBtn);
    fontToolBar->addWidget(italicBtn);
    fontToolBar->addWidget(underlineBtn);
    fontToolBar->addSeparator();
    fontToolBar->addWidget(colorBtn);

    //排序工具条
    //listToolBar = addToolBar("list");
    listToolBar = new QToolBar("list");
    listToolBar->addWidget(listLabel);
    listToolBar->addWidget(listComboBox);
    listToolBar->addSeparator();
    listToolBar->addActions(actGrp->actions());

    addToolBar(fileTool);
    addToolBar(zoomTool);
    addToolBar(rotateTool);
    addToolBar(doToolBar);
    addToolBarBreak();// 类似换行功能
    addToolBar(fontToolBar);
    addToolBar(listToolBar);

}

void ImgProcessor::showNewFile()
{
    ImgProcessor *newImgProcessor = new ImgProcessor;
    newImgProcessor->show();
}

void ImgProcessor::showOpenFile()
{
    fileName = QFileDialog::getOpenFileName(this);
    if (!fileName.isEmpty())
    {
        if (showWidget->text->document()->isEmpty())
        {
            loadFile(fileName);
        }
        else
        {
            ImgProcessor *newImgProcessor = new ImgProcessor;
            newImgProcessor->show();
            newImgProcessor->loadFile(fileName);
        }
    }
}

void ImgProcessor::loadFile(QString filename)
{
    printf("file name:%s\n", filename.data());

    QFile file(filename);
    if (file.open(QIODevice::ReadOnly|QIODevice::Text))
    {
        QTextStream textStream(&file);
        while (!textStream.atEnd())
        {
            showWidget->text->append(textStream.readLine());
            printf("read line\n");
        }
        printf("end\n");
    }

}

void ImgProcessor::showPrintText()
{
    QPrinter *printer;
    QPrintDialog printDialog(printer, this);
    if (printDialog.exec())
    {
        QTextDocument *doc = showWidget->text->document();
        doc->print(printer);
    }
}

void ImgProcessor::ShowZoomIn()
{
    if (img.isNull())//有效性判断
    {
        return;
    }
    QMatrix martix;
    martix.scale(2, 2);//函数返回缩放后的matrix对象引用
    img = img.transformed(martix);
    showWidget->imageLabel->setPixmap(QPixmap::fromImage(img));//重新设置显示图形
}

void ImgProcessor::ShowZoomOut()
{
    if (img.isNull())//有效性判断
    {
        return;
    }
    QMatrix martix;
    martix.scale(0.5, 0.5);//函数返回缩放后的matrix对象引用
    img = img.transformed(martix);
    showWidget->imageLabel->setPixmap(QPixmap::fromImage(img));//重新设置显示图形
}

void ImgProcessor::ShowRotate90()
{
    if (img.isNull())
    {
        return;
    }
    QMatrix matrix;
    matrix.rotate(90);
    img = img.transformed(matrix);
    showWidget->imageLabel->setPixmap(QPixmap::fromImage(img));
}

void ImgProcessor::ShowRotate180()
{
    if (img.isNull())
    {
        return;
    }
    QMatrix matrix;
    matrix.rotate(180);
    img = img.transformed(matrix);
    showWidget->imageLabel->setPixmap(QPixmap::fromImage(img));
}

void ImgProcessor::ShowRotate270()
{
    if (img.isNull())
    {
        return;
    }
    QMatrix matrix;
    matrix.rotate(270);
    img = img.transformed(matrix);
    showWidget->imageLabel->setPixmap(QPixmap::fromImage(img));
}

void ImgProcessor::ShowMirrorVertical()
{
    if (img.isNull())
    {
        return;
    }
    img = img.mirrored(false, true);
    showWidget->imageLabel->setPixmap(QPixmap::fromImage(img));
}

void ImgProcessor::ShowMirrorHorizontal()
{
    if (img.isNull())
    {
        return;
    }
    img = img.mirrored(true, false);
    showWidget->imageLabel->setPixmap(QPixmap::fromImage(img));
}

void ImgProcessor::ShowFontComboBox(QString comboStr)
{
    QTextCharFormat fmt;
    fmt.setFontFamily(comboStr);
    mergeFormat(fmt);
}

void ImgProcessor::mergeFormat(QTextCharFormat format)
{
    QTextCursor cursor = showWidget->text->textCursor();//获取编辑框中的光标
    if (!cursor.hasSelection())
    {
        cursor.select(QTextCursor::WordUnderCursor);
    }
    cursor.mergeCharFormat(format);
    showWidget->text->mergeCurrentCharFormat(format);
}

void ImgProcessor::ShowSizeSpinBox(QString spinValue)
{
    QTextCharFormat fmt;
    fmt.setFontPointSize(spinValue.toFloat());
    showWidget->text->mergeCurrentCharFormat(fmt);
}
void ImgProcessor::ShowBoldBtn()
{
    QTextCharFormat fmt;
    fmt.setFontWeight(boldBtn->isChecked() ? QFont::Bold : QFont::Normal);
    showWidget->text->mergeCurrentCharFormat(fmt);
}
void ImgProcessor::ShowItalicBtn()
{
    QTextCharFormat fmt;
    fmt.setFontItalic(italicBtn->isChecked());
    showWidget->text->mergeCurrentCharFormat(fmt);
}
void ImgProcessor::ShowUnderlineBtn()
{
    QTextCharFormat fmt;
    fmt.setFontUnderline(underlineBtn->isChecked());
    showWidget->text->mergeCurrentCharFormat(fmt);
}
void ImgProcessor::ShowColorBtn()
{
    QColor color = QColorDialog::getColor(Qt::red, this);

    if (color.isValid())
    {
        QTextCharFormat fmt;
        fmt.setForeground(color);
        showWidget->text->mergeCurrentCharFormat(fmt);
    }
}

void ImgProcessor::ShowCurrentFormatChanged(const QTextCharFormat &fmt)
{
    fontComboBox->setCurrentIndex(fontComboBox->findText(fmt.fontFamily()));
    sizeComboBox->setCurrentIndex(sizeComboBox->findText(
                                      QString::number(fmt.fontPointSize())));
    boldBtn->setChecked(fmt.font().bold());
    italicBtn->setChecked(fmt.fontItalic());
    underlineBtn->setChecked(fmt.fontUnderline());
}


void ImgProcessor::ShowList(int index)
{
    QTextCursor cursor = showWidget->text->textCursor();

    if (index != 0)
    {
        QTextListFormat::Style style = QTextListFormat::ListDisc;
        switch(index)
        {
            default:
        case 1:
            style = QTextListFormat::ListDisc; break;
        case 2:
            style = QTextListFormat::ListCircle; break;
        case 3:
            style = QTextListFormat::ListSquare; break;
        case 4:
            style = QTextListFormat::ListDecimal; break;
        case 5:
            style = QTextListFormat::ListLowerAlpha; break;
        case 6:
            style = QTextListFormat::ListUpperAlpha; break;
        case 7:
            style = QTextListFormat::ListLowerRoman; break;
        case 8:
            style = QTextListFormat::ListUpperRoman; break;
        }
        cursor.beginEditBlock();

        QTextBlockFormat blockFmt = cursor.blockFormat();
        QTextListFormat listFmt;

        if (cursor.currentList())
        {
            listFmt = cursor.currentList()->format();
        }
        else
        {
            listFmt.setIndent(blockFmt.indent()+1);
            blockFmt.setIndent(0);
            cursor.setBlockFormat(blockFmt);
        }
        listFmt.setStyle(style);
        cursor.createList(listFmt);

        cursor.endEditBlock();
    }
    else
    {
        QTextBlockFormat bfmt;
        bfmt.setObjectIndex(-1);
        cursor.mergeBlockFormat(bfmt);
    }
}


void ImgProcessor::ShowAlignment(QAction *act)
{
    if (act==leftAction)
    {
        showWidget->text->setAlignment(Qt::AlignLeft);
    }
    if (act==rightAction)
    {
        showWidget->text->setAlignment(Qt::AlignRight);
    }
    if (act==centerAction)
    {
        showWidget->text->setAlignment(Qt::AlignCenter);
    }
    if (act==justifyAction)
    {
        showWidget->text->setAlignment(Qt::AlignJustify);
    }
}

void ImgProcessor::ShowCursorPositionChanged()
{
    if (showWidget->text->alignment() == Qt::AlignLeft)
    {
        leftAction->setChecked(true);
    }
    if (showWidget->text->alignment() == Qt::AlignRight)
    {
        rightAction->setChecked(true);
    }
    if (showWidget->text->alignment() == Qt::AlignCenter)
    {
        centerAction->setChecked(true);
    }
    if (showWidget->text->alignment() == Qt::AlignJustify)
    {
        justifyAction->setChecked(true);
    }
}
