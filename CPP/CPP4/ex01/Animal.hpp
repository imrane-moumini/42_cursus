#ifndef ANIMAL_H
#define ANIMAL_H
#include <iostream>
#include <string>
class Animal {
    public:
        Animal();
        Animal(std::string type);
        Animal(Animal& copy);
        Animal& operator=(Animal& copy);
        virtual ~Animal();
        virtual void makeSound() const;
        std::string getType() const ;
    protected:
        std::string type;

};
#endif