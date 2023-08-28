#include "Zombie.hpp"
Zombie* ZombieHorde( int N, std::string name ){
    Zombie *ZombieArray;

    try {
        //allouer N zombie en une suele allocation
        //initialiser chacun des zombies en donnat le nom passé en param
        //retourne un pointeur sur le premier zombie
        ZombieArray = new Zombie[N];
        for(int i = 0; i < N; i++)
            ZombieArray[i].SetName(name);
        return ZombieArray;
    }
    catch(const std::bad_alloc& e){
        std::cout << "allocation fail" << std::endl;
        return (NULL);
    }
}