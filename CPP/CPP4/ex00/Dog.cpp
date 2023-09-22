#include "Dog.hpp"

Dog::Dog() : Animal("dog"){
    std::cout << "Dog defaut constructor call" << std::endl;
}
Dog::Dog(std::string type): Animal(type){
    std::cout << "Dog type constructor call" << std::endl;
}

Dog::Dog(Dog& copy) :  Animal(copy.type){
    
     std::cout << "Dog copy constructor call" << std::endl;
}

Dog& Dog::operator=(Dog& copy){
    
    std::cout << "Dog copy assignation constructor call" << std::endl;
    this->type = copy.type;
    return (*this);
}

Dog::~Dog(){
    std::cout << "Dog destructor call" << std::endl;
}

void Dog::makeSound() const {
    std::cout << "Dog make a sound" << std::endl;
}