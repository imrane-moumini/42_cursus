#include "Zombie.hpp"

int main()
{
    Zombie		*first_zombie;

	first_zombie = newZombie("Manson");
	first_zombie->announce();
	randomChump("Walker");
	delete first_zombie;

}