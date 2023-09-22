#ifndef WRONGANIMAL_H
#define WRONGANIMAL_H
#include <iostream>
#include <string>
class WrongAnimal {
    public:
        WrongAnimal();
        WrongAnimal(std::string type);
        WrongAnimal(WrongAnimal& copy);
        WrongAnimal& operator=(WrongAnimal& copy);
        virtual ~WrongAnimal();
        void makeSound() const;
        std::string getType() const ;
    protected:
        std::string type;

};
#endif