#include "Array.hpp"

template <typename T>
Array<T>::Array() : array(NULL), length(0){
    std::cout << "default constructor called \n"; 
    try {
        array = new T[10];
    } catch (std::bad_alloc& obj){
        std::cout << obj.what();
    }
}

template <typename T>
Array<T>::Array(Array& copy) : array(NULL),length(copy.size()){
    std::cout << "copy constructor called \n"; 
    try {
        array = new T[copy.size()];
    } catch (std::bad_alloc& obj){
        std::cout << obj.what();
    }
    for (int i = 0; i < length; i++)
        array[i] = copy.array[i];
    
}

template <typename T>
Array<T>& Array<T>::operator=(Array& copy){
    std::cout << "assignement operator called \n"; 
    try {
        array = new T[copy.size()];
        length = copy.size();
    } catch (std::bad_alloc& obj){
        std::cout << obj.what();
    }
    for (unsigned int i = 0; i < length; i++)
        array[i] = copy.array[i];
    return (*this);
}

template <typename T>
Array<T>::Array(unsigned int nbrElement) : array(NULL), length(nbrElement){
    std::cout << "argument constructor called \n"; 
    try {
        array = new T[nbrElement];
    } catch (std::bad_alloc& obj){
        std::cout << obj.what();
    }

    for (unsigned int i = 0; i < nbrElement; i++)
        array[i] = 0;
}

template <typename T>
int Array<T>::size() const{
   return (length);
}

template <typename T>
const char* Array<T>::OutOfBounds::what() const throw(){
    return ("Exception : index is out of Bounds\n");
}

template <typename T>
T Array<T>::operator[](unsigned int i){
    if (i >= length)
        throw (Array::OutOfBounds());
    return (array[i]);
}

template <typename T>
Array<T>::~Array(){
    std::cout << "default destructor called \n"; 
    if (array != NULL)
        delete [] array;
    array = NULL;
}