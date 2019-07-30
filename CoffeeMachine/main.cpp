#include <iostream>
#include <map>
#include "CoffeeMachine.h"

int main()
{
   // std::cout << "Kek\n";
    Recept::components_t components
    {
        {std::make_shared<Product>(Product{"water"}),1},
        {std::make_shared<Product>(Product{"kek"}),2},
        {std::make_shared<Product>(Product{"lol"}),4},
        {std::make_shared<Product>(Product{"lolec"}),1},
    };
    
    Products_t products
    {
        {Product(1,"water"),4},
        {Product(2,"snickers"),4},
        {Product(2,"mars"),3},
        {Product(1,"skitls"),1}
    };
    
    std::vector<std::shared_ptr<Recept>> recepts
    {
        std::make_shared<Recept>(Recept{"esspresso",components}),
        std::make_shared<Recept>(Recept{"mokka",components}),
        std::make_shared<Recept>(Recept{"latte",components}),
        std::make_shared<Recept>(Recept{"capuchino",components})
    };
    
    std::vector<Coffee> coffee
    {
        Coffee{"esspresso",1,recepts[0]},
        Coffee{"mokka",1,recepts[1]},
        Coffee{"latte",1,recepts[2]},
        Coffee{"capuchino",1,recepts[3]}
    };
    
    auto coffeeMachine {CoffeeMachine(products, coffee, components, CoinAcceptor{}, CurrencyAcceptor{})};
    
    coffeeMachine.DepositeMoney(100);
    
    std::cout << coffeeMachine.CanGetCoffee("esspresso") << std::endl;
    std::cout << coffeeMachine.CanGetFood("mars") << std::endl;
    
    coffeeMachine.GiveCoffee("esspresso");
        std::cout << coffeeMachine.CanGetCoffee("esspresso") << std::endl;
    for(auto& kek: coffeeMachine.GetAssortment())
    {
        std::cout << kek.GetName() << " " << kek.GetPrice() << std::endl;
    }
    
    
    return 0;
}
