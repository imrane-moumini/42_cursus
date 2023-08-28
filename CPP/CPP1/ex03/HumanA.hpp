#ifndef HUMAN_A
#define HUMAN_A
#include <string>
#include <iostream>
#include "Weapon.hpp"
class HumanA {

public:
    HumanA();
    HumanA(std::string name, Weapon& arme);
    ~HumanA();
    void attack();
    
private:
    Weapon arme;
    std::string name;
};

#endif