#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat"){
    std::cout << "WrongCat defaut constructor call" << std::endl;
}
WrongCat::WrongCat(std::string type) : WrongAnimal(type){
    std::cout << "WrongCat type constructor call" << std::endl;
}

WrongCat::WrongCat(WrongCat& copy) : WrongAnimal(copy.type){
     std::cout << "WrongCat copy constructor call" << std::endl;
}

WrongCat& WrongCat::operator=(WrongCat& copy){
    std::cout << "WrongCat copy assignation constructor call" << std::endl;
    *this = copy;
    return (*this);
}

WrongCat::~WrongCat(){
    std::cout << "WrongCat destructor call" << std::endl;
}

void WrongCat::makeSound() const {
    std::cout << "WrongCat make a sound" << std::endl;
}