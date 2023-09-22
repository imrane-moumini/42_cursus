#include "Animal.hpp"

Animal::Animal(){
    std::cout << "Animal defaut constructor call" << std::endl;
}
Animal::Animal(std::string type){
    
    std::cout << "Animal type constructor call" << std::endl;
    this->type = type;
}

Animal::Animal(Animal& copy){
    
    std::cout << "Animal copy constructor call" << std::endl;
    this->type = copy.type;
}

Animal& Animal::operator=(Animal& copy){
    
    std::cout << "Animal copy assignation constructor call" << std::endl;
    this->type = copy.type;
    return (*this);
}

Animal::~Animal(){
    std::cout << "Animal destructor call" << std::endl;
}

void Animal::makeSound() const{
    std::cout << "Animal make a sound" << std::endl;
}

std::string Animal::getType() const {
    return (this->type);
}