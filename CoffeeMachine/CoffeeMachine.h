#ifndef COFFEEMACHINE_H
#define COFFEEMACHINE_H
#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include "Acceptor.h"
#include "Product.h"
#include "CoinAcceptor.h"
#include "CurrencyAcceptor.h"
#include "Recept.h"
#include "Order.h"
#include "Coffee.h"
#include <algorithm>

class CoffeeMachine;

typedef  bool (CoffeeMachine::*Pred)(std::string);

class CoffeeMachine
{
private:
    using Products_t = std::vector<std::pair<Product,uint32_t>>;
    std::vector<std::shared_ptr<Recept>> recepts;
    std::vector<Coffee> coffee;
    Products_t products;
    Recept::components_t components;
    uint32_t deposite;
    CoinAcceptor coinAcceptor;
    CurrencyAcceptor currencyAcceptor;
    std::vector<Order> orders;
    void AddToOrder(std::string what);
    std::shared_ptr<Recept> GetRecept(std::string what);
    template<typename T>
    bool CanGet(std::string kind_of, T vector, Pred pred, uint16_t howMany = 1);
public:
    CoffeeMachine(std::vector<std::shared_ptr<Recept>> recepts,
                  Products_t products,
                  Recept::components_t components,
                  CoinAcceptor coinAcceptor,
                  CurrencyAcceptor currencyAcceptor);
    CoffeeMachine();
    bool DepositeMoney(uint32_t money);
    void GetCheck(std::ostream os);
    void GiveCoffee(std::string kindOfCoffee);
    void GiveFood(std::string what);
    bool HasCoffee(std::string kindOfCoffee);
    bool HasFood(std::string kindofFood);
    bool CanGetCoffee(std::string kindOfCoffee, uint16_t howMany = 1);
    bool CanGetFood(std::string kindOfCoffee, uint16_t howMany = 1);
    void AddFood(Product product, uint32_t count);
    void AddComponents(Recept::components_t components);
    std::vector<Product> GetAssortment();
    std::vector<Product> GetAssortmentByDepisote();
    std::vector<Product> GetAssortmentOfCoffeeByDeposite();
    std::vector<Product> GetAssortmentOfFoodByDeposite();
    std::vector<Product> GetAssortmentOfCoffee();
    std::vector<Product> GetAssortmentOfFood();
    ~CoffeeMachine();
};

#endif
