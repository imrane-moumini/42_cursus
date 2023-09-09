#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap("Jonh Doe", 100 , 50,20){ 
    std::cout << "ScavTrap defaut constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name, 100 , 50,20){
    std::cout << "ScavTrap defaut constructor called" << std::endl;
}

ScavTrap::ScavTrap(ScavTrap& copy) : ClapTrap(copy.myName(), copy.nbrHitPoints() , copy.nbrEnergyPoints(),copy.nbrAttackDamage()){ 
    std::cout << "ScavTrap copy constructor called" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& copy){ 
    *this = copy; 
    std::cout << "ScavTrap operator copy constructor called" << std::endl;
    return (*this);
}

ScavTrap::~ScavTrap(){
        std::cout << "ScavTrap default destruct have been called" << std::endl;
}

void ScavTrap::attack(const std::string& target){
        if (this-> nbrHitPoints()> 0)
        {
            std::cout <<  "ScavTrap " << this->myName() << "attacks " << target << " causing " << this->nbrAttackDamage() << " points of damage!" << std::endl;
            this->useEnergyPoints();
        }
        else
            std::cout << "ScavTrap "<< this->myName() << " doesn't have enought Energy points to attack" << std::endl;
}

void ScavTrap::guardGate(){
        std::cout << "ScavTrap is in Gate Keeper mode" << std::endl;
}