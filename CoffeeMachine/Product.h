#ifndef PRODUCT_H
#define PRODUCT_H
#include <iostream>
#include <stdint.h>
#include "Recept.h"

class Recept;

class Product
{
private:
    uint16_t price;
    std::string name;
    std::shared_ptr<Recept> recept;
public:
    Product();
    Product(std::string name);
    Product(uint16_t price, std::string name);
    Product(uint16_t price, std::string name, std::shared_ptr<Recept> recept);
    std::string GetName() const { return name;};
    uint16_t GetPrice() const { return price;};
    std::shared_ptr<Recept> GetRecept() const {return recept;};
    bool HasRecept();
};

bool operator==(const Product& lrh,const Product& rlh);

#endif
