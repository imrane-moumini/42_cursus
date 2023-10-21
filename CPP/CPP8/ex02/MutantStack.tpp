#include "MutantStack.hpp"

template <typename T>
MutantStack<T>::MutantStack() : std::stack<T>() {
    std::cout << "default constructor called\n";
}

template <typename T>
MutantStack<T>::MutantStack(MutantStack& copy) : std::stack<T>(copy){
    std::cout << "copy constructor called\n";
}

template <typename T>
MutantStack<T>& MutantStack<T>::operator=(MutantStack& copy){
    std::cout << "assignement constructor called\n";
    this->c = copy;
    return (*this);
}

template <typename T>
MutantStack<T>::~MutantStack() {
    std::cout << "destructor called\n";
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin() {
    std::cout << "begin method called\n";
    return (this->c.begin());
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end() {
    std::cout << "end method called\n";
    return (this->c.end());
}

template <typename T>
typename MutantStack<T>::reverse_iterator MutantStack<T>::rbegin() {
    std::cout << "begin method called\n";
    return (this->c.rbegin());
}

template <typename T>
typename MutantStack<T>::reverse_iterator MutantStack<T>::rend() {
    std::cout << "end method called\n";
    return (this->c.rend());
}

template <typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::cbegin() const{
    std::cout << "cbegin method called\n";
    return (this->c.cbegin());
}

template <typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::cend() const{
    std::cout << "cend method called\n";
    return (this->c.cend());
}

template <typename T>
typename MutantStack<T>::const_reverse_iterator MutantStack<T>::crbegin() const{
    std::cout << "cbegin method called\n";
    return (this->c.crbegin());
}

template <typename T>
typename MutantStack<T>::const_reverse_iterator MutantStack<T>::crend() const{
    std::cout << "cend method called\n";
    return (this->c.crend());
}