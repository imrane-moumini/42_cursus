#include "HumanA.hpp"

void HumanA::attack(){
    std::cout << name << " attack with their " << arme.getType() << std::endl;
};

HumanA::HumanA(std::string name, Weapon& arme) : arme(arme){
    this->name = name;
};

HumanA::~HumanA(){
};
