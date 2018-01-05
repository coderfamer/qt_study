#ifndef LCOMBOBOX_H
#define LCOMBOBOX_H

#include <QComboBox>
#include <QLabel>
#include <QHBoxLayout>
#include "lglobal.h"

class LComboBox : public QComboBox
{
    Q_OBJECT
    Q_PROPERTY(QVariantList boxItems READ boxItems WRITE setBoxItems)
    Q_PROPERTY(QVariant currentValue READ currentValue WRITE setCurrentValue NOTIFY currentValueChanged)
    //Q_PROPERTY(bool wheelEnabled READ wheelEnabled WRITE setWheelEnabled)
    L_DECLARE_PRIVATE(LComboBox)
public:
    explicit LComboBox(QWidget *iParent = 0);
signals:
    void itemsChanged();
    void currentValueChanged();
    void valueChecked();

public slots:
    QVariant currentValue() const;
    void setCurrentValue(const QVariant &iValue);

    void setBoxItems(const QVariantList &iItems);
    QVariantList boxItems() const;
    QIcon currentIcon() const;
    QVariant currentUserData() const;

    QHBoxLayout *pack(const QString &iWidgetType, const QString &iText);

//    void setWheelEnabled(bool iEnabled);
//    bool wheelEnabled() const;
//    void restoreStyle();

//protected:
//    void wheelEvent(QWheelEvent *iEvent);

};

#endif // LCOMBOBOX_H
