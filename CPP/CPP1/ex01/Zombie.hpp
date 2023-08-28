#ifndef ZOMBIE_H
#define ZOMBIE_H
#include <string>
#include <iostream>


class Zombie {

private:
    std::string name;

public:
    Zombie();
    Zombie(std:: string name);
    ~Zombie();
    void announce(void);
    void SetName(std:: string name);
   
};

Zombie* ZombieHorde(int N, std::string name );
#endif
