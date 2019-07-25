#include "Coffee.h"

Coffee::Coffee()
{
    
}

Coffee::Coffee(std::string name):Product{name}
{
    
}

Coffee::Coffee(std::string name, uint16_t price, std::shared_ptr<Recept> recept):Product(price, name),recept{recept}
{
    
}


