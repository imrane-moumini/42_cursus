#ifndef CLAP_TRAP
#define CLAP_TRAP
#include <iostream>
#include <string>

class ClapTrap{
    public:
        ClapTrap();
        ClapTrap(std::string name);
        ClapTrap(std::string name, int hitPoints, int EnergyPoints, int AttackDamage);
        ClapTrap(ClapTrap& copy);
        ClapTrap& operator=(ClapTrap& copy);
        ~ClapTrap();

        virtual void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
        std::string myName();
        int nbrHitPoints();
        int nbrEnergyPoints();
        int nbrAttackDamage();
        void useEnergyPoints();


    private:
        std::string name;
        int HitPoints;
        int EnergyPoints;
        int AttackDamage;

};

#endif