#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : HitPoints(10),EnergyPoints(10), AttackDamage(0){
    std::cout << "ClapTrap default construt have been called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : HitPoints(10),EnergyPoints(10), AttackDamage(0){
    std::cout << "ClapTrap argumen name construt have been called" << std::endl;
    this->name = name;
}

ClapTrap::ClapTrap(ClapTrap& copy){
    std::cout << "ClapTrap copy construt have been called" << std::endl;
    this->name = copy.name;
    this->HitPoints = copy.HitPoints;
    this->EnergyPoints = copy.EnergyPoints;
    this->AttackDamage = copy.AttackDamage;
}

ClapTrap& ClapTrap::operator=(ClapTrap& copy){
    std::cout << "ClapTrap assignment  operator construt have been called" << std::endl;
    this->name = copy.name;
    this->HitPoints = copy.HitPoints;
    this->EnergyPoints = copy.EnergyPoints;
    this->AttackDamage = copy.AttackDamage;
    return (*this);
}

ClapTrap::~ClapTrap(){
        std::cout << "ClapTrap default destruct have been called" << std::endl;
}

void ClapTrap::attack(const std::string& target){
        if (this->EnergyPoints > 0)
        {
            std::cout <<     "ClapTrap " << this->name << "attacks " << target << " causing " << this->AttackDamage << " points of damage!" << std::endl;
            this->EnergyPoints--;
        }
        else
            std::cout << "ClapTrap "<< this->name << " doesn't have enought Energy points to attack" << std::endl;
}

int ClapTrap::nbrHitPoints() const{
    return (HitPoints);
};

int ClapTrap::nbrEnergyPoints() const {
    return (EnergyPoints);
};

int ClapTrap::nbrAttackDamage() const{
    return (AttackDamage);
};

std::string ClapTrap::myName() const{
    return (name);
};

void ClapTrap::useEnergyPoints(){
    EnergyPoints--;
};
void ClapTrap::beRepaired(unsigned int amount){
        if (this->EnergyPoints > 0)
        {
            std::cout <<  "ClapTrap " << this->name << "have been repared and gain " << amount << " hit points" << std::endl;
            this->HitPoints = this->HitPoints + amount;
            this->EnergyPoints--;
        }
        else
            std::cout << "ClapTrap "<< this->name << " doesn't have enought Energy points to be repaired" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount){
    std::cout <<  "ClapTrap " << this->name << "have been attacked and lost" << amount << " hit points" << std::endl;
}

