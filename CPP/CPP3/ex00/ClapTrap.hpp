#ifndef CLAP_TRAP
#define CLAP_TRAP
#include <iostream>
#include <string>

class ClapTrap{
    public:
        ClapTrap();
        ClapTrap(std::string name);
        ClapTrap(ClapTrap& copy);
        ClapTrap& operator=(ClapTrap& copy);
        ~ClapTrap();

        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
        std::string getName(void);
        int getHitPoints(void);
        int getEnergyPoints(void);
        int getAttackDamage(void);


    private:
        std::string name;
        int HitPoints;
        int EnergyPoints;
        int AttackDamage;

};

#endif