#include "lcombobox.h"
#include <QDebug>
#include <QVariantMap>
#include "ldataconverter.h"
#include "lfilesystem.h"

/*****************************LComboBoxPrivate*****************************************/
class LComboBoxPrivate : public QObject
{
    Q_OBJECT
public:
    explicit LComboBoxPrivate(LComboBox * parent):QObject(parent),dd(parent)
    {

    }

    LComboBox * const dd;
    QVariantList m_itemList;
    QVariantMap m_itemMap;
};



/*****************************LComboxBox*****************************************************/
#include "lcombobox.moc"

LComboBox::LComboBox(QWidget *iParent):dp(new LComboBoxPrivate(this))
{
}

QVariant LComboBox::currentValue() const
{
    return  currentData();
}

void LComboBox::setCurrentValue(const QVariant &iValue)
{
    Q_UNUSED(iValue);
}

void LComboBox::setBoxItems(const QVariantList &iItems)
{
    dp->m_itemList = iItems;
    for(int i = 0; i < iItems.count();i++)
    {
        QVariantMap map = iItems.at(i).toMap();
        this->addItem(map.value("text").toString(),map.value("name"));
        dp->m_itemMap.insert(map.value("text").toString(),map.value("name"));
    }
}

QVariantList LComboBox::boxItems() const
{
    return dp->m_itemList;
}

QIcon LComboBox::currentIcon() const
{
    /* QPixmap pixmap;
    pixmap.loadFromData(dp->m_itemList.at(currentIndex()).toMap().value("icon").toBitArray());
    QIcon icon;
    icon.addPixmap(pixmap);
    return icon;*/
}

QVariant LComboBox::currentUserData() const
{
    return currentData();
}

QHBoxLayout* LComboBox::pack(const QString &iWidgetType,const QString &iText)
{
    QHBoxLayout *hbox = new QHBoxLayout();
    if (iWidgetType == "Label") {
        QLabel *label = new QLabel(iText,this);
        hbox->addWidget(label);
        return hbox;
    }
    else
    {
        return 0;
    }
}


