#include "Product.h"

Product::Product(uint16_t price, std::string name):price{price},name{name}
{
    
}

Product::Product()
{
    
}

Product::Product(std::string name):name{name}
{
    
}

Product::Product(uint16_t price, std::string name, std::shared_ptr<Recept> recept):price{price},name{name},recept{recept}
{
    
}

bool operator==(const Product& lrh,const Product& rlh)
{
    return lrh.GetName() == rlh.GetName();
}
