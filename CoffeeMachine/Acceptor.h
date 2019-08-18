#ifndef ACCEPTOR_H
#define ACCEPTOR_H
#include <iostream>
#include <vector>
#include <set>
#include <stdint.h>
#include "IUnitMoney.h"

class Acceptor
{
    typedef std::vector<std::pair<uint32_t,uint32_t>> units_money_t;
protected:
    units_money_t units_money;
    std::set<uint16_t> kind_money;
    Acceptor(std::vector<IUnitMoney> money);
    Acceptor(units_money_t units_money);
    Acceptor();
public:
    virtual bool GiveMoney(size_t count) = 0;
    virtual bool TakeMoney(IUnitMoney unit) = 0;
    virtual void GiveChange(uint32_t howmany) = 0;
    virtual bool HasChange(uint32_t count) = 0;
    const units_money_t& GetInfoAboutMoney(){ return units_money;};
};

#endif
