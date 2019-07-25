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

bool operator==(const Product& lrh,const Product& rlh)
{
    return lrh.GetName() == rlh.GetName();
}

bool Product::operator<(const Product& obj)
{
    return this->GetName() < obj.GetName();
}
