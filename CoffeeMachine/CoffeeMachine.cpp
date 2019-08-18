#include "CoffeeMachine.h"

CoffeeMachine::CoffeeMachine(Products_t products,
     std::vector<Coffee> coffee,
     Recept::components_t components,
     CoinAcceptor coinAcceptor, CurrencyAcceptor currencyAcceptor):
    products{products}, coffee{coffee}, components{components},coinAcceptor{coinAcceptor},currencyAcceptor{currencyAcceptor}
{
    
}

std::shared_ptr<Recept> CoffeeMachine::GetRecept(std::string what)
{
    return std::find_if(coffee.begin(), coffee.end(), [&what](auto&el){
        return el.GetName() == what;
    })->GetRecept();
}

void CoffeeMachine::GetCheck(std::ostream os)
{
    
}

bool CoffeeMachine::DepositeMoney(uint32_t money)
{
    if(!coinAcceptor.HasChange(money))
        return false;
    deposite = money;
    orders.push_back(Order{});
    return true;
}

bool CoffeeMachine::HasCoffee(std::string what)
{
    auto recept = GetRecept(what);
    auto comps = recept->GetComponets();
    for(auto&comp:comps)
    {
        bool has = false;
        for(auto&el:components)
        {
            if((comp.first == el.first?(has = true):false) && comp.second > el.second)
                return false;
        }
        if (!has)
        {
            return false;
        }
    }
    return true;
}
                              
bool CoffeeMachine::HasFood(std::string what)
{
    for(auto& prod: products)
    {
        if (prod.first.GetName() == what && prod.second > 0)
            return true;
    }
    return false;
}

bool CoffeeMachine::CanGetCoffee(std::string what)
{
    if(coinAcceptor.HasChange(deposite) && HasCoffee(what))
    {
        if((std::find_if(coffee.begin(), coffee.end(), [&what](auto&el){
            return el.GetName() == what;
        }))->GetPrice() <= deposite)
            return true;
        else
            return false;
    }
    else
        return false;
}

bool CoffeeMachine::CanGetFood(std::string what)
{
    if(coinAcceptor.HasChange(deposite))
        if(HasFood(what))
        {
            if((std::find_if(products.begin(), products.end(), [&what](auto&el){
                return el.first.GetName() == what;
            }))->second > 0)
                return true;
            else
                return false;
        }
        else
            return  false;
    else
        return false;
}

void CoffeeMachine::GiveCoffee(std::string what)
{
    if(CanGetCoffee(what))
    {
        auto recept = GetRecept(what);
        for(auto& comp:recept->GetComponets())
        {
            for(auto&component:components)
            {
                if(comp.first->GetName() == component.first->GetName())
                {
                    component.second -= comp.second;
                    break;
                }
            }
        }
        AddToOrder(what);
    }
    else
        throw "Can't give coffee";
}

void CoffeeMachine::AddToOrder(std::string what)
{
    auto price = std::find_if(products.begin(), products.end(), [&what](auto&el)
                              {
                                  return el.first == what;
                              })->first.GetPrice();
    orders.back().Add(what,price);
}

void CoffeeMachine::AddToOrder(std::shared_ptr<Product> what)
{
    orders.back().Add(what->GetName(),what->GetPrice());
}

void CoffeeMachine::GiveFood(std::string what)
{
    if(CanGetFood(what))
    {
        auto it = std::find_if(products.begin(), products.end(), [&what](auto&el)
             {
                 return el.first == what;
             });
        it->second--;
        AddToOrder(std::make_shared<decltype(it->first)>(it->first));
    }
    else
        throw "Can't give food";
}

void CoffeeMachine::AddFood(Product product, uint32_t count)
{
    auto iter = std::find_if(products.begin(),products.end(),[&product](auto& el)
                             {
                                 return el.first == product;
                             });
    if(iter == products.end())
    {
        products.push_back({product, count});
    }
    else
    {
        iter->second+=count;
    }
    
}

void CoffeeMachine::AddComponents(Recept::components_t components)
{
    for(auto&comp:this->components)
    {
        for (auto i = components.size()-1; i !=0; i--)
        {
          if(comp.first->GetName() == components[i].first->GetName())
          {
              comp.second += components[i].second;
              components.erase(components.begin()+i);
          }
        }
    }
    std::copy(components.begin(),components.end(),std::back_inserter(this->components));
}

std::vector<Product> CoffeeMachine::GetAssortmentOfCoffeeByDeposite()
{
    auto result = GetAssortmentOfCoffee();
    auto it = result.begin();
    while (it != result.end())
    {
        if (it->GetPrice() > deposite)
            it = result.erase(it);
        else
            ++it;
    }
    return result;
}

std::vector<Product> CoffeeMachine::GetAssortment()
{
    auto food = GetAssortmentOfFood();
    auto coffee = GetAssortmentOfCoffee();
    food.insert(food.end(), coffee.begin(), coffee.end());
    return food;
}

std::vector<Product> CoffeeMachine::GetAssortmentByDepisote()
{
    auto food = GetAssortmentOfFoodByDeposite();
    auto coffee = GetAssortmentOfCoffeeByDeposite();
    food.insert(food.end(), coffee.begin(), coffee.end());
    return food;
}

std::vector<Product> CoffeeMachine::GetAssortmentOfFoodByDeposite()
{
    std::vector<Product> result;
    for(auto& prod: products)
    {
        if(prod.first.GetPrice() < deposite)
            result.push_back(prod.first);
    }
    return result;
}
std::vector<Product> CoffeeMachine::GetAssortmentOfCoffee()
{
    std::vector<Product> result;
    std::copy(coffee.begin(),coffee.end(),std::back_inserter(result));
    return result;
}
std::vector<Product> CoffeeMachine::GetAssortmentOfFood()
{
    std::vector<Product> result;
    for(auto& prod: products)
    {
        result.push_back(prod.first);
    }
    return result;
}

CoffeeMachine::CoffeeMachine()
{
}

CoffeeMachine::~CoffeeMachine()
{
}
