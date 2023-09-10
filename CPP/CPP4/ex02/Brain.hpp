#ifndef BRAIN_H
#define BRAIN_H
#include <iostream>
#include <string>

class Brain {
    public:
        Brain();
        Brain(Brain& copy);
        Brain& operator=(Brain& copy);
        ~Brain();
        std::string ideas[100];
        std::string get_idea(int index);
        void set_idea(int index, std::string idea);

};
#endif