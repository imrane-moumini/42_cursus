#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap("Jonh Doe", 100 , 100,30){ 
    std::cout << "FragTrap defaut constructor called" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name, 100 , 100,30){
    std::cout << "FragTrap defaut constructor called" << std::endl;
}

FragTrap::FragTrap(FragTrap& copy) : ClapTrap(copy.myName(), copy.nbrHitPoints() , copy.nbrEnergyPoints(),copy.nbrAttackDamage()){ 
    std::cout << "FragTrap copy constructor called" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& copy){ 
    *this = copy; 
    std::cout << "FragTrap operator copy constructor called" << std::endl;
    return (*this);
}

FragTrap::~FragTrap(){
        std::cout << "FragTrap default destruct have been called" << std::endl;
}

void FragTrap::attack(const std::string& target){
        if (this-> nbrHitPoints()> 0)
        {
            std::cout <<  "FragTrap " << this->myName() << "attacks " << target << " causing " << this->nbrAttackDamage() << " points of damage!" << std::endl;
            this->useEnergyPoints();
        }
        else
            std::cout << "FragTrap "<< this->myName() << " doesn't have enought Energy points to attack" << std::endl;
}

void FragTrap::highFivesGuys(){
        std::cout << "HIGH FIVE !!" << std::endl;
}