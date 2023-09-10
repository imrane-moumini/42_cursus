#ifndef CAT_H
#define CAT_H
#include <iostream>
#include <string>
#include "Animal.hpp"
#include "Brain.hpp"
class Cat : public Animal{
    public:
        Cat();
        Cat(std::string type);
        Cat(Cat& copy);
        Cat& operator=(Cat& copy);
        ~Cat();
        void makeSound() const;
        std::string getIdea(int index);
        void setIdea(int index, std::string idea);
    private:
        Brain* BrainPtr;

};
#endif