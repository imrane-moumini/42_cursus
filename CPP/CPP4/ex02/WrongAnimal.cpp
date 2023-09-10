#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(){
    std::cout << "WrongAnimal defaut constructor call" << std::endl;
}
WrongAnimal::WrongAnimal(std::string type){
    
    std::cout << "WrongAnimal type constructor call" << std::endl;
    this->type = type;
}

WrongAnimal::WrongAnimal(WrongAnimal& copy){
    
     std::cout << "WrongAnimal copy constructor call" << std::endl;
    *this = copy;
}

WrongAnimal& WrongAnimal::operator=(WrongAnimal& copy){
    
    std::cout << "WrongAnimal copy assignation constructor call" << std::endl;
    *this = copy;
    return (*this);
}

WrongAnimal::~WrongAnimal(){
    std::cout << "WrongAnimal destructor call" << std::endl;
}

void WrongAnimal::makeSound() const{
    std::cout << "WrongAnimal make a sound" << std::endl;
}

std::string WrongAnimal::getType() const {
    return (this->type);
}