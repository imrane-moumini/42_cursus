#ifndef WRONGCAT_H
#define WRONGCAT_H
#include <iostream>
#include <string>
#include "WrongAnimal.hpp"
class WrongCat : public WrongAnimal{
    public:
        WrongCat();
        WrongCat(std::string type);
        WrongCat(WrongCat& copy);
        WrongCat& operator=(WrongCat& copy);
        ~WrongCat();
        void makeSound() const;

};
#endif