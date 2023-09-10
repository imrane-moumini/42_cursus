#ifndef DOG_H
#define DOG_H
#include <iostream>
#include <string>
#include "Animal.hpp"
#include "Brain.hpp"
class Dog : public Animal{
    public:
        Dog();
        Dog(std::string type);
        Dog(Dog& copy);
        Dog& operator=(Dog& copy);
        ~Dog();
        void makeSound() const;
        std::string getIdea(int index);
        void setIdea(int index, std::string idea);
    private:
        Brain* BrainPtr;

};
#endif