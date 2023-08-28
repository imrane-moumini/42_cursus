#include "Zombie.hpp"

void Zombie::announce(){
    std::cout << name << ":" << "BraiiiiiiinnnzzzZ...\n";
}

Zombie::Zombie(std::string name){
    this->name = name;
};

Zombie::Zombie(){

};

Zombie::~Zombie(){
    std::cout << this->name << " have been destroyed\n";
}

void Zombie::SetName(std:: string name){
    this->name = name;
}