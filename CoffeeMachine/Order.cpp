#include "Order.h"

Order::Order()
{
    
}


void Order::Add(std::string what, uint16_t price)
{
    whatOrdered.push_back(what);
    sum += price;
}

Order::Order(std::vector<std::string> whatOrdered, uint16_t sum, std::time_t time):whatOrdered{whatOrdered},sum{sum},time{time}
{
    
}
