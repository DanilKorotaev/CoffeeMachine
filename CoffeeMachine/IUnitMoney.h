#ifndef IUnitMoney_hpp
#define IUnitMoney_hpp
#include <stdint.h>
#include <iostream>

class IUnitMoney
{
public:
    uint32_t value;
    std::string name;
};

#endif /* IUnitMoney_hpp */
