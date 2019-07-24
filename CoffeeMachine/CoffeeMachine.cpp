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

bool CoffeeMachine::DepositeMoney(uint32_t money)
{
    if(!coinAcceptor.HasChange(money))
        return false;
    deposite = money;
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
        
    }
    else
        throw "Can't give coffee";
}

void CoffeeMachine::GiveFood(std::string what)
{
    if(CanGetFood(what))
    {
        std::find_if(products.begin(), products.end(), [&what](auto&el)
             {
                 return el.first == what;
             })->second--;
    }
    else
        throw "Can't give food";
}

void CoffeeMachine::AddFood(Product product, uint32_t count)
{
    
}

std::vector<Product> CoffeeMachine::GetAssortmentOfCoffeeByDeposite()
{
    return {};
}
std::vector<Product> CoffeeMachine::GetAssortmentOfFoodByDeposite()
{
    return {};
}
std::vector<Product> CoffeeMachine::GetAssortmentOfCoffee()
{
    return {};
}
std::vector<Product> CoffeeMachine::GetAssortmentOfFood()
{
    return {};
}

CoffeeMachine::CoffeeMachine()
{
}

CoffeeMachine::~CoffeeMachine()
{
}