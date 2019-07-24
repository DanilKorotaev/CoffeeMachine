#ifndef ACCEPTOR_H
#define ACCEPTOR_H
#include <iostream>
#include <vector>
#include <stdint.h>
#include "IUnitMoney.h"

class Acceptor
{
    typedef std::vector<std::pair<IUnitMoney,uint32_t>> units_money_t;
protected:
    units_money_t units_money;
    Acceptor(std::vector<IUnitMoney> money);
    Acceptor(units_money_t units_money);
    Acceptor();
public:
    bool GiveMoney(size_t count);
    bool TakeMoney(IUnitMoney unit);
    void GiveChange(uint32_t howmany);
    bool HasChange(uint32_t count);
    const units_money_t& GetInfoAboutMoney(){ return units_money;};
};

#endif
