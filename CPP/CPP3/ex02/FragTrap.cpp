#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap("Jonh Doe"){ 
    std::cout << "FragTrap defaut constructor called" << std::endl;
    this->HitPoints = 100;
    this->EnergyPoints = 100;
    this->AttackDamage = 30;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name){
    std::cout << "FragTrap name constructor called" << std::endl;
    this->HitPoints = 100;
    this->EnergyPoints = 100;
    this->AttackDamage = 30;
}

FragTrap::FragTrap(FragTrap& copy) : ClapTrap(copy.name){ 
    std::cout << "FragTrap copy constructor called" << std::endl;
    this->HitPoints = copy.HitPoints;
    this->EnergyPoints = copy.EnergyPoints;
    this->AttackDamage = copy.AttackDamage;
}

FragTrap& FragTrap::operator=(const FragTrap& copy){ 
    std::cout << "FragTrap operator copy constructor called" << std::endl;
    this->name = copy.name;
    this->HitPoints = copy.HitPoints;
    this->EnergyPoints = copy.EnergyPoints;
    this->AttackDamage = copy.AttackDamage;
    return (*this);
}

FragTrap::~FragTrap(){
        std::cout << "FragTrap default destruct have been called" << std::endl;
}

void FragTrap::attack(const std::string& target){
        if (this->EnergyPoints > 0)
        {
            std::cout <<  "FragTrap " << this->name << " attacks " << target << " causing " << this->AttackDamage << " points of damage!" << std::endl;
            this->EnergyPoints--;
        }
        else
            std::cout << "FragTrap "<< this->name<< " doesn't have enought Energy points to attack" << std::endl;
}

void FragTrap::highFivesGuys(){
        std::cout << this->name << " asks for a HIGH FIVE !!" << std::endl;
}