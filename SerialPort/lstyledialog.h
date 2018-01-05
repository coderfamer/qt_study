#ifndef LSTYLEDIALOG_H
#define LSTYLEDIALOG_H
#include <QObject>

#if defined(LsDlg)
#undef LsDlg
#endif
#define LsDlg LStyleDialog::instance()

class LStyleDialog : public QObject
{
private:
    explicit LStyleDialog(QObject *iParent = 0);
public:
    static LStyleDialog *instance();
public slots:
    void aboutUs(QWidget *iParent = 0);
//    void aboutQt(QWidget *iParent = 0);

//    void information(const QString &iText, QWidget *iParent = 0, const QString &iTitle = QString(), int iAutoCloseSeconds = 0);
//    void warning(const QString &iText, QWidget *iParent = 0, const QString &iTitle = QString(), int iAutoCloseSeconds = 0);
    void error(const QString &iText, QWidget *iParent = 0, const QString &iTitle = QString(), int iAutoCloseSeconds = 0);

//    QString question(const QString &iText,
//                     QWidget *iParent = 0,
//                     const QString &iTitle = QString(),
//                     const QStringList &iButtons = QStringList(),
//                     const QString &iDetailText = QString(),
//                     const QString &iInformativeText = QString(),
//                     int iDefaultButtonNumber = 0,
//                     int iEscapeButtonNumber = -1,
//                     int iAutoCloseSeconds = 0);

//    QString getText(QWidget *iParent = 0,
//                    const QString &iLabel = QString(),
//                    const QString &iTitle = QString(),
//                    const QString &iDefaultText = QString(),
//                    bool *oOk = 0);

//    QString getItem(const QStringList &iItems,
//                    const QString &iLabel,
//                    QWidget *iParent = 0,
//                    const QString &iTitle = QString(),
//                    int iCurrent = 0,
//                    bool iEditable = true,
//                    bool *oOk = 0);

//    int getInt(const QString &iLabel,
//               QWidget *iParent = 0,
//               const QString &iTitle = QString(),
//               int iValue = 0,
//               int iStep = 1,
//               bool *oOk = 0);

//    double getDouble(const QString &iLabel,
//                     QWidget *iParent = 0,
//                     const QString &iTitle = QString(),
//                     double iValue = 0,
//                     int iDecimals = 1,
//                     bool *oOk = 0);

//    QString getPassword(QWidget *iParent = 0,
//                        const QString &iLabel = QString(),
//                        const QString &iTitle = QString());

//    QString	getExistingDirectory(QWidget *iParent = 0,
//                                 const QString &iCaption = QString(),
//                                 const QString &iDir = QString(),
//                                 QFileDialog::Options iOptions = QFileDialog::ShowDirsOnly);

//    QString	getOpenFileName(QWidget *iParent = 0,
//                            const QString &iCaption = QString(),
//                            const QString &iDir = QString(),
//                            const QString &iFilter = QString(),
//                            QString *oSelectedFilter = 0,
//                            QFileDialog::Options iOptions = 0);

//    QStringList	getOpenFileNames(QWidget *iParent = 0,
//                                 const QString &iCaption = QString(),
//                                 const QString &iDir = QString(),
//                                 const QString &iFilter = QString(),
//                                 QString *oSelectedFilter = 0,
//                                 QFileDialog::Options iOptions = 0);

//    QString	getSaveFileName(QWidget *iParent = 0,
//                            const QString &iCaption = QString(),
//                            const QString &iDir = QString(),
//                            const QString &iFilter = QString(),
//                            QString *oSelectedFilter = 0,
//                            QFileDialog::Options iOptions = 0);

//    QVariantMap getUiPanelInfo(const QString &iTitle,
//                               const QString &iContent,
//                               QObject *iCurrent,
//                               const QVariantMap &iDefaultData = QVariantMap(),
//                               QWidget *iParent = 0,
//                               const QVariantMap &iOption = QVariantMap());

};

#endif // LSTYLEDIALOG_H
