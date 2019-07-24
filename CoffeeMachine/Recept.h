#ifndef RECEPT_H
#define RECEPT_H
#include <iostream>
#include "Product.h"
#include <vector>
#include <stdint.h>
#include <unordered_map>

class Product;

class Recept
{
public:
    typedef std::vector<std::pair<std::shared_ptr<Product>,uint32_t>> components_t;
    Recept();
    Recept(std::string Productname, components_t components);
    const std::string& GetName() const { return Productname; };
    const components_t& GetComponets() const {return components;};
private:
    std::string Productname;
    components_t components;
};

#endif
