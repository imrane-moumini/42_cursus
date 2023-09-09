#include "FragTrap.hpp"

int	main(void)
{
	FragTrap ok("bob");
	

	ok.attack("B");
	ok.takeDamage(5);
	ok.beRepaired(3);
	ok.highFivesGuys();
	std::cout << "nbr attack Damage " << ok.nbrAttackDamage() << std::endl;
	std::cout << "nbr EnergyPoints " << ok.nbrEnergyPoints() << std::endl;
	std::cout << "nbr HitPoints " << ok.nbrHitPoints() << std::endl;

	return (0);
}