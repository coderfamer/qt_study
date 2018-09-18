#include <QKeySequence>
#include <QApplication>
#include <QMessageBox>
#include <QFileDialog>
#include <QIODevice>
#include "imgprocessor.h"

ImgProcessor::ImgProcessor(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowTitle(tr("Easy Word"));

    showWidget = new ShowWidget(this);
    setCentralWidget(showWidget);

    listLabel = new QLabel(tr("sort"));
    listComboBox = new QComboBox;
    listComboBox->addItem("standard");
    listComboBox->addItem("QTextListFormat::ListDisc");
    listComboBox->addItem("QTextListFormat::ListCircle");
    listComboBox->addItem("QTextListFormat::ListSquare");
    listComboBox->addItem("QTextListFormat::ListDecimal");
    listComboBox->addItem("QTextListFormat::ListLowerAlpha");
    listComboBox->addItem("QTextListFormat::ListUpperAlpha");
    listComboBox->addItem("QTextListFormat::ListLowerRoman");
    listComboBox->addItem("QTextListFormat::ListUpperRoman");
//    QTextListFormat::ListDisc;
//    QTextListFormat::ListCircle
//    QTextListFormat::ListSquare
//    QTextListFormat::ListDecimal
//    QTextListFormat::ListLowerAlpha
//    QTextListFormat::ListUpperAlpha
//    QTextListFormat::ListLowerRoman
//    QTextListFormat::ListUpperRoman


    fontLabel1 = new QLabel(tr("Font:"));
    fontComboBox = new QFontComboBox;
    fontComboBox->setFontFilters(QFontComboBox::ScalableFonts);

    fontLabel2 = new QLabel(tr("Size:"));
    sizeComboBox = new QComboBox;
    QFontDatabase db;
    foreach (int size, db.standardSizes())
        sizeComboBox->addItem(QString::number(size));

    boldBtn = new QToolButton;
    boldBtn->setIcon(QIcon(":/images/blod.png"));
    boldBtn->setCheckable(true);
    italicBtn = new QToolButton;
    italicBtn->setIcon(QIcon(":/images/italic.png"));
    italicBtn->setCheckable(true);

    underlineBtn = new QToolButton;
    underlineBtn->setIcon(QIcon(":/images/underline.png"));
    underlineBtn->setCheckable(true);

    colorBtn = new QToolButton;
    colorBtn->setIcon(QIcon(":/images/color.png"));
    colorBtn->setCheckable(true);


    createActions();
    createMenus();
    createToolBars();


    if (img.load(":/images/butterfly.png"))
    {
        showWidget->imageLabel->setPixmap(QPixmap::fromImage(img));
    }

    connect(fontComboBox, SIGNAL(activated(QString)), this, SLOT(showFontComboBox(QString)) );
    connect(sizeComboBox, SIGNAL(activated(QString)), this, SLOT(showSizeSpinBox(QString)) );
    connect(boldBtn, &QToolButton::clicked, this, &ImgProcessor::showBoldBtn );
    connect(italicBtn, &QToolButton::clicked, this, &ImgProcessor::showItalicBtn );
    connect(underlineBtn, &QToolButton::clicked, this, &ImgProcessor::showUnderlineBtn );
    connect(colorBtn, &QToolButton::clicked, this, &ImgProcessor::showColorBtn );
    connect(showWidget->text, SIGNAL(currentCharFormatChanged(const QTextCharFormat &)),
            this, SLOT(showCurrentFormatChanged(const QTextCharFormat &)) );

    connect(listComboBox, SIGNAL(activated(int)), this, SLOT(showList(int)) );
    connect(showWidget->text->document(), SIGNAL(undoAvailable(bool)),
            redoAction, SLOT(setEnabled(bool)) );
    connect(showWidget->text->document(), SIGNAL(redoAvailable(bool)),
            redoAction, SLOT(setEnabled(bool)) );
    connect(showWidget->text, SIGNAL(cursorPositionChanged()),
            this, SLOT(showCursorPositionChanged()) );

}

ImgProcessor::~ImgProcessor()
{

}

void ImgProcessor::createActions()
{
    openFileAction = new QAction(QIcon(":/images/open.png"), tr("open"), this);
    openFileAction->setShortcut(tr("Ctrl + O"));
    //openFileAction->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_O));
    openFileAction->setStatusTip(tr("open  file"));
    connect(openFileAction, SIGNAL(triggered(bool)), this, SLOT(showOpenFile()) );

    newFileAction = new QAction(QIcon(":/images/new.png"), tr("new"), this);
    newFileAction->setShortcut(tr("Ctrl + N"));
    //openFileAction->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_O));
    newFileAction->setStatusTip(tr("new  file"));
    connect(newFileAction, SIGNAL(triggered(bool)), this, SLOT(showNewFile()) );

    exitAction = new QAction(QIcon(":/images/exit.png"), tr("quit"), this);
    exitAction->setShortcut(tr("Ctrl + Q"));
    //openFileAction->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_O));
    exitAction->setStatusTip(tr("quit process"));
    connect(exitAction, SIGNAL(triggered()), this, SLOT(close()) );

    copyAction = new QAction(QIcon(":/images/copy.png"), tr("cppy"), this);
    copyAction->setShortcut(tr("Ctrl + C"));
    //openFileAction->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_O));
    copyAction->setStatusTip(tr("copy a file"));
    connect(copyAction, SIGNAL(triggered()), showWidget->text, SLOT(copy()) );

    cutAction = new QAction(QIcon(":/images/cut.png"), tr("cut"), this);
    cutAction->setShortcut(tr("Ctrl + X"));
    //openFileAction->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_O));
    cutAction->setStatusTip(tr("cut a file"));
    //connect(cutAction, SIGNAL(triggered()), showWidget->text, SLOT(cut()) );
    connect(cutAction, &QAction::triggered, showWidget->text,  &QTextEdit::cut);

    pasteAction = new QAction(QIcon(":/images/paste.png"), tr("paste"), this);
    pasteAction->setShortcut(tr("Ctrl + V"));
    //openFileAction->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_O));
    pasteAction->setStatusTip(tr("paste a file"));
    connect(pasteAction, SIGNAL(triggered()), showWidget->text, SLOT(paste()) );

    aboutAction = new QAction(QIcon(":/images/about.png"), tr("about"), this);
    connect(aboutAction, SIGNAL(triggered()), qApp, SLOT(aboutQt()) );


    printTextAction = new QAction(QIcon(":/images/print_text.png"), tr("print text"), this);
    printTextAction->setStatusTip(tr("print a text"));
    connect(printTextAction, SIGNAL(triggered(bool)), this, SLOT(showPrintText()) );

    printImageAction = new QAction(QIcon(":/images/print_image.png"), tr("print image"), this);
    printImageAction->setStatusTip(tr("print image"));
    connect(printImageAction, SIGNAL(triggered(bool)), this, SLOT(showPrintImage()) );

    zoomInAction = new QAction(QIcon(":/images/zoom-in.png"), tr("zoom-in"), this);
    zoomInAction->setStatusTip(tr("zoom in a pricture"));
    connect(zoomInAction, SIGNAL(triggered(bool)), this, SLOT(showZoomIn()) );

    zoomOutAction = new QAction(QIcon(":/images/zoom_out.png"), tr("zoom out"), this);
    zoomOutAction->setStatusTip(tr("zoom out a picture"));
    connect(zoomOutAction, SIGNAL(triggered(bool)), this, SLOT(showZoomOut()) );

    rotate90Action = new QAction(QIcon(":/images/rotate90.png"), tr("rotate 90"), this);
    rotate90Action->setStatusTip(tr("rotate picture 90"));
    connect(rotate90Action, SIGNAL(triggered(bool)), this, SLOT(showRotate90()) );

    rotate180Action = new QAction(QIcon(":/images/rotate180.png"), tr("rotate 180"), this);
    rotate180Action->setStatusTip(tr("rotate 180"));
    connect(rotate180Action, SIGNAL(triggered(bool)), this, SLOT(showRotate180()) );

    rotate270Action = new QAction(QIcon(":/images/rotate270.png"), tr("rotate270"), this);
    rotate270Action->setStatusTip(tr("rotate 270"));
    connect(rotate270Action, SIGNAL(triggered(bool)), this, SLOT(showRotate270()) );

    mirrorVerticalAction = new QAction(QIcon(":/images/vertical-mirror.png"), tr("vertial mirror"), this);
    mirrorVerticalAction->setStatusTip(tr("vertial mirror"));
    connect(mirrorVerticalAction, SIGNAL(triggered(bool)), this, SLOT(showMirrorVertical()) );

    mirrorHorizontalAction = new QAction(QIcon(":/images/horizontal-mirror.png"), tr("h m"), this);
    mirrorHorizontalAction->setStatusTip(tr("h m"));
    connect(mirrorHorizontalAction, SIGNAL(triggered(bool)), this, SLOT(showMirrorHorizontal()) );

    undoAction = new QAction(QIcon(":/images/undo.png"), tr("undo"), this);
    connect(undoAction, SIGNAL(triggered(bool)), showWidget->text, SLOT(undo()) );

    redoAction = new QAction(QIcon(":/images/redo.png"), tr("redo"), this);
    connect(redoAction, SIGNAL(triggered(bool)), showWidget->text, SLOT(redo()) );


    actGrp = new QActionGroup(this);
    leftAction = new QAction(QIcon(":/images/left-justify.png"), "left justify", actGrp);
    leftAction->setCheckable(true);

    rightAction = new QAction(QIcon(":/images/right-justify.png"), "right justify", actGrp);
    rightAction->setCheckable(true);

    centerAction = new QAction(QIcon(":/images/center.png"), "center", actGrp);
    centerAction->setCheckable(true);

    justifyAction = new QAction(QIcon(":/images/justify.png"), "justify", actGrp);
    justifyAction->setCheckable(true);

    connect(actGrp, SIGNAL(triggered(QAction*)), this, SLOT(showAlignment(QAction*)) );
}

void ImgProcessor::createMenus()
{
    fileMenu = menuBar()->addMenu(tr("File"));
    fileMenu->addAction(openFileAction);
    fileMenu->addAction(newFileAction);
    fileMenu->addAction(printTextAction);
    fileMenu->addAction(printImageAction);
    fileMenu->addSeparator();
    fileMenu->addAction(exitAction);

    zoomMenu = menuBar()->addMenu(tr("editor"));
    zoomMenu->addAction(copyAction);
    zoomMenu->addAction(cutAction);
    zoomMenu->addAction(pasteAction);
    zoomMenu->addAction(aboutAction);
    zoomMenu->addSeparator();
    zoomMenu->addAction(zoomInAction);
    zoomMenu->addAction(zoomOutAction);

    rotateMenu = menuBar()->addMenu(tr("Zotate"));
    rotateMenu->addAction(rotate90Action);
    rotateMenu->addAction(rotate180Action);
    rotateMenu->addAction(rotate270Action);

    mirrorMenu = menuBar()->addMenu(tr("Mirror"));
    mirrorMenu->addAction(mirrorVerticalAction);
    mirrorMenu->addAction(mirrorHorizontalAction);

}

void ImgProcessor::createToolBars()
{
    fileTool = addToolBar("File");
    fileTool->addAction(openFileAction);
    fileTool->addAction(newFileAction);
    fileTool->addAction(printTextAction);
    fileTool->addAction(printImageAction);

    zoomTool = addToolBar("edit");
    zoomTool->addAction(copyAction);
    zoomTool->addAction(cutAction);
    zoomTool->addAction(pasteAction);
    zoomTool->addSeparator();
    zoomTool->addAction(zoomInAction);
    zoomTool->addAction(zoomOutAction);

    rotateTool = addToolBar("rotate");
    rotateTool->addAction(rotate90Action);
    rotateTool->addAction(rotate180Action);
    rotateTool->addAction(rotate270Action);

    doToolBar = addToolBar("doEdit");
    doToolBar->addAction(undoAction);
    doToolBar->addAction(redoAction);

    fontToolBar = addToolBar("Font");
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

    listToolBar = addToolBar("list");
    listToolBar->addWidget(listLabel);
    listToolBar->addWidget(listComboBox);
    listToolBar->addSeparator();
    listToolBar->addActions(actGrp->actions());

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
    if (file.open(QIODevice::ReadOnly | QIODevice::Text))
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
    QPrinter printer;
    QPrintDialog printDialog(&printer, this);
    if (printDialog.exec())
    {
        QTextDocument *doc = showWidget->text->document();
        doc->print(&printer);
    }
}

void ImgProcessor::showPrintImage()
{
    QPrinter printer;
    QPrintDialog printDialog(&printer, this);
    if (printDialog.exec())
    {
        QPainter painter(&printer);
        QRect rect = painter.viewport();
        QSize size = img.size();
        size.scale(rect.size(), Qt::KeepAspectRatio);

        painter.setViewport(rect.x(), rect.y(), size.width(), size.height());
        painter.setWindow(img.rect());
        painter.drawImage(0, 0, img);
    }
}

void ImgProcessor::showZoomIn()
{
    if (img.isNull())
        return;
    QMatrix martix;
    martix.scale(2, 2);
    img = img.transformed(martix);
    showWidget->imageLabel->setPixmap(QPixmap::fromImage(img));
}

void ImgProcessor::showZoomOut()
{
    if (img.isNull())
        return;
    QMatrix martix;
    martix.scale(0.5, 0.5);
    img = img.transformed(martix);
    showWidget->imageLabel->setPixmap(QPixmap::fromImage(img));
}

void ImgProcessor::showRotate90()
{
    if (img.isNull())
        return;
    QMatrix matrix;
    matrix.rotate(90);
    img = img.transformed(matrix);
    showWidget->imageLabel->setPixmap(QPixmap::fromImage(img));
}

void ImgProcessor::showRotate180()
{
    if (img.isNull())
        return;
    QMatrix matrix;
    matrix.rotate(180);
    img = img.transformed(matrix);
    showWidget->imageLabel->setPixmap(QPixmap::fromImage(img));
}

void ImgProcessor::showRotate270()
{
    if (img.isNull())
        return;
    QMatrix matrix;
    matrix.rotate(270);
    img = img.transformed(matrix);
    showWidget->imageLabel->setPixmap(QPixmap::fromImage(img));
}

void ImgProcessor::showMirrorVertical()
{
    if (img.isNull())
        return;
    img = img.mirrored(false, true);
    showWidget->imageLabel->setPixmap(QPixmap::fromImage(img));
}

void ImgProcessor::showMirrorHorizontal()
{
    if (img.isNull())
        return;
    img = img.mirrored(true, false);
    showWidget->imageLabel->setPixmap(QPixmap::fromImage(img));
}

void ImgProcessor::showFontComboBox(QString comboStr)
{
    QTextCharFormat fmt;
    fmt.setFontFamily(comboStr);
    mergeFormat(fmt);

}

void ImgProcessor::mergeFormat(QTextCharFormat format)
{
    QTextCursor cursor = showWidget->text->textCursor();
    if (!cursor.hasSelection())
        cursor.select(QTextCursor::WordUnderCursor);

    cursor.mergeCharFormat(format);
    showWidget->text->mergeCurrentCharFormat(format);
}

void ImgProcessor::showSizeSpinBox(QString spinValue)
{
    QTextCharFormat fmt;
    fmt.setFontPointSize(spinValue.toFloat());
    showWidget->text->mergeCurrentCharFormat(fmt);

}

void ImgProcessor::showBoldBtn()
{
    QTextCharFormat fmt;
    fmt.setFontWeight(boldBtn->isChecked() ? QFont::Bold : QFont::Normal);
    showWidget->text->mergeCurrentCharFormat(fmt);
}

void ImgProcessor::showItalicBtn()
{
    QTextCharFormat fmt;
    fmt.setFontItalic(italicBtn->isChecked());
    showWidget->text->mergeCurrentCharFormat(fmt);
}

void ImgProcessor::showUnderlineBtn()
{
    QTextCharFormat fmt;
    fmt.setFontUnderline(underlineBtn->isChecked());
    showWidget->text->mergeCurrentCharFormat(fmt);
}

void ImgProcessor::showColorBtn()
{
    QColor color = QColorDialog::getColor(Qt::red, this);

    if (color.isValid())
    {
        QTextCharFormat fmt;
        fmt.setForeground(color);
        showWidget->text->mergeCurrentCharFormat(fmt);
    }
}

void ImgProcessor::showCurrentFormatChanged(const QTextCharFormat &fmt)
{
    fontComboBox->setCurrentIndex(fontComboBox->findText(fmt.fontFamily()));;
    sizeComboBox->setCurrentIndex(sizeComboBox->findText(QString::number(fmt.fontPointSize())));
    boldBtn->setChecked(fmt.font().bold());
    italicBtn->setChecked(fmt.fontItalic());
    underlineBtn->setChecked(fmt.fontUnderline());
}


void ImgProcessor::showAlignment(QAction *act)
{
    if (act == leftAction)
        showWidget->text->setAlignment(Qt::AlignLeft);
    if (act == rightAction)
        showWidget->text->setAlignment(Qt::AlignRight);
    if (act == centerAction)
        showWidget->text->setAlignment(Qt::AlignCenter);
    if (act == justifyAction)
        showWidget->text->setAlignment(Qt::AlignJustify);
}

void ImgProcessor::showCursorPositionChanged()
{
    if (showWidget->text->alignment() == Qt::AlignLeft)
        leftAction->setChecked(true);
    if (showWidget->text->alignment() == Qt::AlignRight)
        rightAction->setChecked(true);
    if (showWidget->text->alignment() == Qt::AlignCenter)
        centerAction->setChecked(true);
    if (showWidget->text->alignment() == Qt::AlignJustify)
        justifyAction->setChecked(true);
}

void ImgProcessor::showList(int index)
{
    QTextCursor cursor = showWidget->text->textCursor();

    if (index != 0)
    {
        QTextListFormat::Style style = QTextListFormat::ListDisc;
        switch (index) {
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
        case 61:
            style = QTextListFormat::ListUpperAlpha; break;
        case 7:
            style = QTextListFormat::ListLowerRoman; break;
        case 8:
            style = QTextListFormat::ListUpperRoman; break;

        default:
            break;
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
            listFmt.setIndent(blockFmt.indent() + 1);
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
        //cursor.mergeBlockCharFormat(bfmt);
    }
}
