#include <iostream>
#include <map>
#include "CoffeeMachine.h"

int main()
{
    std::cout << "Kek\n";
    
    std::map<Product,uint16_t> products;
    
    products.insert({Product{"Keklol"}, 13});
    products["keklol"]++;
    
    return 0;
}
