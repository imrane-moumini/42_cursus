#ifndef HUMAN_B
#define HUMAN_B
#include <string>
#include <iostream>
#include "Weapon.hpp"
class HumanB {

public:
    HumanB();
    HumanB(std::string name);
    ~HumanB();
    void attack();
    void setWeapon(Weapon& arme);
    
private:
    Weapon arme;
    std::string name;
};

#endif