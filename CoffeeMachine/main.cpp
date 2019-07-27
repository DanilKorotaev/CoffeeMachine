#include <iostream>
#include <map>
#include "CoffeeMachine.h"

int main()
{
    std::cout << "Kek\n";
    Recept::components_t components
    {
        {std::make_shared<Product>(Product{"water"}),1},
        {std::make_shared<Product>(Product{"kek"}),2},
        {std::make_shared<Product>(Product{"lol"}),4},
        {std::make_shared<Product>(Product{"lolec"}),1},
    };
    
    Products_t products
    {
        {Product(1,"1"),4},
        {Product(2,"2"),4},
        {Product(2,"3"),3},
        {Product(1,"4"),1}
    };
    
    std::vector<std::shared_ptr<Recept>> recepts
    {
        std::make_shared<Recept>(Recept{"1",components}),
        std::make_shared<Recept>(Recept{"2",components}),
        std::make_shared<Recept>(Recept{"3",components}),
        std::make_shared<Recept>(Recept{"4",components})
    };
    
    std::vector<Coffee> coffee
    {
        Coffee{"1",1,recepts[0]},
        Coffee{"2",1,recepts[1]},
        Coffee{"4",1,recepts[2]},
        Coffee{"4",1,recepts[3]}
    };
    
    auto coffeeMachine {CoffeeMachine(//recepts,
                                      products, coffee, components, CoinAcceptor{}, CurrencyAcceptor{})};
    
    std::cout << coffeeMachine.CanGetCoffee("1") << std::endl;
    std::cout << coffeeMachine.CanGetFood("1") << std::endl;
    for(auto& kek: coffeeMachine.GetAssortment())
    {
        std::cout << kek.GetName() << " " << kek.GetPrice() << std::endl;
    }
    return 0;
}
