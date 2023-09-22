#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap("Jonh Doe"){ 
    std::cout << "ScavTrap defaut constructor called" << std::endl;
    this->HitPoints = 100;
    this->EnergyPoints = 50;
    this->AttackDamage = 20;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name){
    std::cout << "ScavTrap defaut constructor called" << std::endl;
    this->name = name;
    this->HitPoints = 100;
    this->EnergyPoints = 50;
    this->AttackDamage = 20;
}

ScavTrap::ScavTrap(ScavTrap& copy) : ClapTrap(copy.name){ 
    std::cout << "ScavTrap copy constructor called" << std::endl;
    this->HitPoints = copy.HitPoints;
    this->EnergyPoints = copy.EnergyPoints;
    this->AttackDamage = copy.AttackDamage;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& copy){ 
    std::cout << "ScavTrap operator copy constructor called" << std::endl;
    this->name = name;
    this->HitPoints = copy.HitPoints;
    this->EnergyPoints = copy.EnergyPoints;
    this->AttackDamage = copy.AttackDamage;
    return (*this);
}

ScavTrap::~ScavTrap(){
        std::cout << "ScavTrap default destruct have been called" << std::endl;
}

void ScavTrap::attack(const std::string& target){
        if (this->HitPoints > 0)
        {
            std::cout <<  "ScavTrap " << this->name << " attacks " << target << " causing " << this->AttackDamage << " points of damage!" << std::endl;
            this->EnergyPoints--;
        }
        else
            std::cout << "ScavTrap "<< this->name << " doesn't have enought Energy points to attack" << std::endl;
}

void ScavTrap::guardGate(){
        std::cout << "ScavTrap is in Gate Keeper mode" << std::endl;
}