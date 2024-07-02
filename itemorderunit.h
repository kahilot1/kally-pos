#ifndef ITEMORDERUNIT_H
#define ITEMORDERUNIT_H

class ItemOrderUnit
{
public:
    ItemOrderUnit(int unitOrderID, int itemID, int orderID, int quantity);
private:
    int m_unitOrderID;
    int m_itemID;
    int m_orderID;
    int m_quantity;
};

#endif // ITEMORDERUNIT_H
