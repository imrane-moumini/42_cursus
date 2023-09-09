#ifndef DOG_H
#define DOG_H
#include <iostream>
#include <string>
#include "Animal.hpp"
class Dog : public Animal{
    public:
        Dog();
        Dog(std::string type);
        Dog(Dog& copy);
        Dog& operator=(Dog& copy);
        ~Dog();
        void makeSound() const;

};
#endif