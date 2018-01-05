#ifndef COMMIX_H
#define COMMIX_H
#include "lglobal.h"
#include "lbasedialog.h"
#include <QWidget>
#include <QDialog>
#include <QMouseEvent>
#include <QSerialPort>

class Commix : public LBaseDialog
{
    Q_OBJECT
    L_DECLARE_PRIVATE(Commix)
public:
    explicit Commix(QWidget *parent = 0);

signals:
    void resetSignal(int baudRate, int stopBits, int dataBits, int flowControl, int parity);
protected:
    bool eventFilter(QObject *obj, QEvent *event);
    void doToolButtonSkin();

public slots:
    void doOpen();
    void doReset();
    void freeClear();
    void testClear();
    void doAboutUs();
    void doToolButtonSet();
    void sendMessage();
    void startTest();
    void endTest();
    void textChanged(const QString &iText);
    void changedResult();

private:
    void initLayout();
};

#endif // COMMIX_H
