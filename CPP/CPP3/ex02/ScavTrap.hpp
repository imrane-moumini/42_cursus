#ifndef SCAVTRAP_H
#define SCAVTRAP_H
#include "ClapTrap.hpp"
class ScavTrap : public ClapTrap {
    public:
    ScavTrap();
    ScavTrap(std::string name);
    ScavTrap(ScavTrap& copy);
    ScavTrap& operator=(const ScavTrap& copy);
    ~ScavTrap();
    void attack(const std::string& target);
    void guardGate();

};
#endif