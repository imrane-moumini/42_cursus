#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap a("A");
	ClapTrap b("B");
	ClapTrap c("");
	
	a.attack("B");
	b.takeDamage(5);
	b.beRepaired(3);
	b.attack("A");
	a.takeDamage(10);
	a.beRepaired(10);
	a.attack("B");
	c.attack("B");
	return (0);

    std::string bob = "bob";
}