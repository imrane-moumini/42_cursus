#include "ScavTrap.hpp"

int	main(void)
{
	ScavTrap ok("bob");
	

	ok.attack("B");
	ok.takeDamage(5);
	ok.beRepaired(3);
	ok.guardGate();
	std::cout << "nbr attack Damage " << ok.nbrAttackDamage() << std::endl;
	std::cout << "nbr EnergyPoints " << ok.nbrEnergyPoints() << std::endl;
	std::cout << "nbr HitPoints " << ok.nbrHitPoints() << std::endl;

	return (0);
}