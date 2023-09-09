#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : HitPoints(10),EnergyPoints(10), AttackDamage(0){
    std::cout << "ClapTrap default construt have been called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : HitPoints(10),EnergyPoints(10), AttackDamage(0){
    std::cout << "ClapTrap argumen name construt have been called" << std::endl;
    this->name = name;
}

ClapTrap::ClapTrap(std::string name, int hitPoints, int EnergyPoints, int AttackDamage)
 : HitPoints(hitPoints),EnergyPoints(EnergyPoints), AttackDamage(AttackDamage){
    std::cout << "ClapTrap argumen all construt have been called" << std::endl;
    this->name = name;
} 
ClapTrap::ClapTrap(ClapTrap& copy){
    std::cout << "ClapTrap copy construt have been called" << std::endl;
    *this = copy;
}

ClapTrap& ClapTrap::operator=(ClapTrap& copy){
    std::cout << "ClapTrap assignment  operator construt have been called" << std::endl;
    *this = copy;
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

int ClapTrap::nbrHitPoints(){
    return (HitPoints);
};

int ClapTrap::nbrEnergyPoints(){
    return (EnergyPoints);
};

int ClapTrap::nbrAttackDamage(){
    return (AttackDamage);
};

std::string ClapTrap::myName(){
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

