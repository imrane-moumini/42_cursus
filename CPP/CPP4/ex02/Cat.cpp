#include "Cat.hpp"

Cat::Cat() : Animal("Cat"){
    std::cout << "Cat defaut constructor call" << std::endl;
    BrainPtr = new Brain; 
}
Cat::Cat(std::string type) : Animal(type){
    std::cout << "Cat type constructor call" << std::endl;
    BrainPtr = new Brain; 
}

Cat::Cat(Cat& copy) : Animal(copy.type){
     std::cout << "Cat copy constructor call" << std::endl;
     BrainPtr = new Brain;
    if (copy.BrainPtr)
    {
        for (int i = 0; i < 100; i++)
            BrainPtr->ideas[i] = copy.BrainPtr->ideas[i];
    }
    if (copy.BrainPtr)
        delete copy.BrainPtr;
    copy.BrainPtr = NULL;
}

Cat& Cat::operator=(Cat& copy){
    std::cout << "Cat copy assignation constructor call" << std::endl;
    delete BrainPtr;
    this->type = copy.type;
    BrainPtr = new Brain;
    if (copy.BrainPtr)
    {
        for (int i = 0; i < 100; i++)
            BrainPtr->ideas[i] = copy.BrainPtr->ideas[i];
    }
    if (copy.BrainPtr != NULL)
        delete copy.BrainPtr; 
    copy.BrainPtr = NULL;
    return (*this);
}

Cat::~Cat(){
    std::cout << "Cat destructor call" << std::endl;
    delete BrainPtr;
}

void Cat::makeSound() const {
    std::cout << "Cat make a sound" << std::endl;
}

std::string Cat::getIdea(int index){
    return BrainPtr->get_idea(index);
}

void Cat::setIdea(int index, std::string idea){
    return BrainPtr->set_idea(index, idea);
}