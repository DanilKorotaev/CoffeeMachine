#ifndef CURRCENCYACCEPTOR_H
#define CURRCENCYACCEPTOR_H
#include "Acceptor.h"

class CurrencyAcceptor: public Acceptor
{
private:
    enum class KindOfMoney {TEN = 10, FIFTY = 50, HUNDRED = 100};
public:
    CurrencyAcceptor();
    virtual bool HasChange(uint32_t count) override;
    virtual bool GiveMoney(size_t count) override;
    virtual bool TakeMoney(IUnitMoney unit) override;
    virtual void GiveChange(uint32_t howmany) override;
};

#endif
