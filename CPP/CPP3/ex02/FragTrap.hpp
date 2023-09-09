#ifndef FRAGTRAP_H
#define FRAGTRAP_H
#include "ScavTrap.hpp"
class FragTrap : public ClapTrap {
    public:
    FragTrap();
    FragTrap(std::string name);
    FragTrap(FragTrap& copy);
    FragTrap& operator=(const FragTrap& copy);
    ~FragTrap();
    void attack(const std::string& target);
    void highFivesGuys();

};
#endif