#ifndef CAT_H
#define CAT_H
#include <iostream>
#include <string>
#include "Animal.hpp"
class Cat : public Animal{
    public:
        Cat();
        Cat(std::string type);
        Cat(Cat& copy);
        Cat& operator=(Cat& copy);
        ~Cat();
        void makeSound() const;

};
#endif