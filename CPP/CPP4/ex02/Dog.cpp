#include "Dog.hpp"

Dog::Dog() : Animal("dog"){
    std::cout << "Dog defaut constructor call" << std::endl;
    BrainPtr = new Brain; 
}
Dog::Dog(std::string type): Animal(type){
    std::cout << "Dog type constructor call" << std::endl;
    BrainPtr = new Brain; 
}

Dog::Dog(Dog& copy) :  Animal(copy.type){
    std::cout << "Dog copy constructor call" << std::endl;
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

Dog& Dog::operator=(Dog& copy){
    std::cout << "Dog copy assignation constructor call" << std::endl;
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

Dog::~Dog(){
    std::cout << "Dog destructor call" << std::endl;
    if (BrainPtr != NULL)
        delete BrainPtr;
}

void Dog::makeSound() const {
    std::cout << "Dog make a sound" << std::endl;
}

std::string Dog::getIdea(int index){
    return BrainPtr->get_idea(index);
}

void Dog::setIdea(int index, std::string idea){
    return BrainPtr->set_idea(index, idea);
}