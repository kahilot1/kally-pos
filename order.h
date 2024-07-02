#ifndef ORDER_H
#define ORDER_H
#include <item.h>
#include <itemorderunit.h>
#include <vector>

class Order
{
public:
    Order(const int& orderID, const std::vector<ItemOrderUnit>& contents);
private:
    int m_orderID;
    std::vector<ItemOrderUnit> m_contents;
public:
    ItemOrderUnit getOrderItem(int position = 0);


};

#endif // ORDER_H
