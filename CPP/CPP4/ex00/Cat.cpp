#include "Cat.hpp"

Cat::Cat() : Animal("Cat"){
    std::cout << "Cat defaut constructor call" << std::endl;
}
Cat::Cat(std::string type) : Animal(type){
    std::cout << "Cat type constructor call" << std::endl;
}

Cat::Cat(Cat& copy) : Animal(copy.type){
     std::cout << "Cat copy constructor call" << std::endl;
}

Cat& Cat::operator=(Cat& copy){
    std::cout << "Cat copy assignation constructor call" << std::endl;
    this->type = copy.type;
    return (*this);
}

Cat::~Cat(){
    std::cout << "Cat destructor call" << std::endl;
}

void Cat::makeSound() const {
    std::cout << "Cat make a sound" << std::endl;
}