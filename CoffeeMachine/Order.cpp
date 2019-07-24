#include "Order.h"

Order::Order()
{
    
}
Order::Order(std::vector<std::string> whatOrdered, uint16_t sum, std::time_t time):whatOrdered{whatOrdered},sum{sum},time{time}
{
    
}
