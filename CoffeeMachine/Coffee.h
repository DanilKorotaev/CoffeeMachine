#ifndef Coffee_h
#define Coffee_h
#include <iostream>
#include <stdint.h>
#include "Recept.h"
#include "Product.h"

class Coffee: public Product
{
private:
    std::shared_ptr<Recept> recept;
public:
    Coffee();
    Coffee(std::string name);
    Coffee(std::string name, uint16_t price, std::shared_ptr<Recept> recept);
    std::shared_ptr<Recept> GetRecept() const {return recept;};
};

#endif /* Coffee_hpp */
