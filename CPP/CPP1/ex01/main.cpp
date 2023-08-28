#include "Zombie.hpp"

int main()
{
    int i = 0;
    Zombie* ZombieArray = ZombieHorde(5, "Paul");
    while (i < 5)
    {
        ZombieArray[i].announce();
        i++;
    }
    delete[] ZombieArray;


}