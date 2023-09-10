#include "Brain.hpp"

Brain::Brain() {
    std::cout << "Brain defaut constructor call" << std::endl;
}

Brain::Brain(Brain& copy) {
    *this = copy;
    std::cout << "Brain copy constructor call" << std::endl;
}

Brain& Brain::operator=(Brain& copy){
    std::cout << "Brain copy assignation constructor call" << std::endl;
    *this = copy;
    return (*this);
}

Brain::~Brain(){
    std::cout << "Brain destructor call" << std::endl;
}

std::string Brain::get_idea(int index){
    if (index >= 0 && index <= 99)
        return ideas[index];
    else
        std::cout << "Wrong index\n";
    return "Wrong index\n";
}

void Brain::set_idea(int index, std::string idea){
    if (index >= 0 && index <= 99)
        ideas[index] = idea;
    else
        std::cout << "Wrong index\n";
}
