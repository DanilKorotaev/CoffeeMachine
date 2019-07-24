#ifndef CURRCENCYACCEPTOR_H
#define CURRCENCYACCEPTOR_H
#include "Acceptor.h"

class CurrencyAcceptor: public Acceptor
{
private:
    enum class KindOfMoney {TEN = 10, FIFTY = 50, HUNDRED = 100};
public:
    CurrencyAcceptor();
};

#endif
