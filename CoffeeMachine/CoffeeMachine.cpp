#include "CoffeeMachine.h"

CoffeeMachine::CoffeeMachine(std::vector<std::shared_ptr<Recept>> recepts,
         Products_t products,
         Recept::components_t components,
         CoinAcceptor coinAcceptor, CurrencyAcceptor currencyAcceptor):
products{products}, components{components},coinAcceptor{coinAcceptor},currencyAcceptor{currencyAcceptor},recepts{recepts}
{
    
}

std::shared_ptr<Recept> CoffeeMachine::GetRecept(std::string what)
{
    auto res = std::find_if(recepts.begin(),recepts.end(),[what](const auto& el){
        return el->GetName() == what;
    });
    
    return (res != recepts.end() ? *res : nullptr);
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

bool CoffeeMachine::HasCoffee(std::string kindOfCoffee)
{
    if (auto recept = GetRecept(kindOfCoffee); recept != nullptr)
    {
        auto comps = (recept)->GetComponets();
        for(auto&comp:comps)
        {
            for(auto&el:components)
            {
                if(comp.first == el.first && comp.second < el.second)
                    return false;
            }
        }
        return true;
    }
    return false;
}
                              
bool CoffeeMachine::HasFood(std::string kindofFood)
{
    for(auto& prod: products)
    {
        if (prod.first.GetName() == kindofFood && prod.second > 0)
            return true;
    }
    return false;
}

template<typename T>
bool CoffeeMachine::CanGet(std::string kind_of, T vector, Pred pred, uint16_t howMany)
{
    if(coinAcceptor.HasChange(deposite))
        if((this->*pred)(kind_of))
        {
            if((std::find_if(vector.begin(), vector.end(), [&kind_of](auto&el){
                return el.first.GetName() == kind_of;
            }))->second >= howMany)
                return true;
            else
                return false;
        }
        else
            return  false;
    else
        return false;
}

bool CoffeeMachine::CanGetCoffee(std::string kindOfCoffee, uint16_t howMany)
{
    if(CanGet(kindOfCoffee,products,&CoffeeMachine::HasCoffee,howMany))
     return true;
    else return false;
}

bool CoffeeMachine::CanGetFood(std::string kindOfCoffee, uint16_t howMany)
{
    if(CanGet(kindOfCoffee,products,&::CoffeeMachine::HasFood,howMany))
        return true;
    else return false;
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

void CoffeeMachine::GiveFood(std::string what)
{
    if(CanGetFood(what))
    {
        std::find_if(products.begin(), products.end(), [&what](auto&el)
             {
                 return el.first == what;
             })->second--;
        AddToOrder(what);
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
    for(auto&comp:components)
    {
        this->components.push_back({comp.first,comp.second});
    }
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
    return {};
}

std::vector<Product> GetAssortmentByDepisote()
{
  return {};
}

std::vector<Product> CoffeeMachine::GetAssortmentOfFoodByDeposite()
{
    std::vector<Product> result;
    for(auto& prod: products)
    {
       // if(prod.first.GetRecept() == nullptr && prod.first.GetPrice() < deposite)
            result.push_back(prod.first);
    }
    return result;
}
std::vector<Product> CoffeeMachine::GetAssortmentOfCoffee()
{
    std::vector<Product> result;
    for(auto& prod: products)
    {
      //  if(prod.first.GetRecept() != nullptr)
            result.push_back(prod.first);
    }
    return result;
}
std::vector<Product> CoffeeMachine::GetAssortmentOfFood()
{
    std::vector<Product> result;
    for(auto& prod: products)
    {
       // if(prod.first.GetRecept() == nullptr)
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
