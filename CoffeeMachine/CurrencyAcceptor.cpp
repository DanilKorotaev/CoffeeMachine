#include "CurrencyAcceptor.h"

CurrencyAcceptor::CurrencyAcceptor()
{
    
}

bool CurrencyAcceptor::HasChange(uint32_t count)
{
    return true;
}

void CurrencyAcceptor::GiveChange(uint32_t howmany)
{
    
}

bool CurrencyAcceptor::GiveMoney(size_t count)
{
    return true;
}

bool CurrencyAcceptor::TakeMoney(IUnitMoney unit)
{
    return true;
}
