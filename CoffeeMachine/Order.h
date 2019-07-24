#ifndef Order_hpp
#define Order_hpp
#include <ctime>
#include <iostream>
#include <vector>
#include <stdint.h>

class Order
{
private:
    std::time_t time;
    std::vector<std::string> whatOrdered;
    uint16_t sum;
public:
    Order();
    Order(std::vector<std::string> whatOrdered, uint16_t sum, std::time_t time = std::time(nullptr));
    std::vector<std::string> WhatOrdered() const {return whatOrdered;};
    void Add(std::string what, uint16_t price);
    uint16_t GetSum() const { return sum;}
    std::time_t GetTimeOrder()const {return time;}
};

#endif /* Order_hpp */
