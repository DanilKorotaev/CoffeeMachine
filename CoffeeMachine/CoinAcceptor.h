#ifndef COINACCEPTOR_H
#define COINACCEPTOR_H
#include "Acceptor.h"
#include <map>
class CoinAcceptor: public Acceptor
{
public:
    enum class KindOfMoney {ONE = 1, TWO = 2, FIVE = 5, TEN = 10};
    CoinAcceptor();
    virtual bool HasChange(uint32_t count) override;
    virtual bool GiveMoney(size_t count) override;
    bool TakeMoney(KindOfMoney unit);
    virtual void GiveChange(uint32_t howmany) override;
private:
    std::map<KindOfMoney,uint32_t> units_money;
};

#endif
