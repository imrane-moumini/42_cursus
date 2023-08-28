#include "Zombie.hpp"

Zombie* newZombie(std::string name){
    Zombie* newZ;

    try {
        newZ = new Zombie(name);
        return newZ;
    }
    catch(const std::bad_alloc& e){
        std::cout << "allocation fail" << std::endl;
        return (NULL);
    }
}