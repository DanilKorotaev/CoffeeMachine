#ifndef COINACCEPTOR_H
#define COINACCEPTOR_H
#include "Acceptor.h"

class CoinAcceptor: public Acceptor
{
public:
    enum class KindOfMoney {ONE = 1, TWO = 2, FIVE = 5, TEN = 10};
    CoinAcceptor();
    bool HasChange(uint32_t count);
};

#endif