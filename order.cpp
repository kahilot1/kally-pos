#include "order.h"

Order::Order(const int& orderID, const std::vector<ItemOrderUnit>& contents)
    :m_orderID(orderID), m_contents(contents){}
