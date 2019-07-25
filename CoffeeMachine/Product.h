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
public:
    Product();
    Product(std::string name);
    Product(uint16_t price, std::string name);
    std::string GetName() const { return name;};
    uint16_t GetPrice() const { return price;};
    bool HasRecept();
    bool operator<(const Product& obj);
    friend bool operator==(const Product& lrh,const Product& rlh);
};

bool operator==(const Product& lrh,const Product& rlh);

#endif
