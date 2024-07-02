#ifndef ITEM_H
#define ITEM_H
#include <QString>

class Item
{
public:
    Item(const QString& name, const int& price, const QString& details, const int& itemID);

private:
    QString m_name;
    int m_price;
    QString m_details;
    int m_itemID;
};

#endif // ITEM_H
