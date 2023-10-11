#ifndef ARRAY_H
#define ARRAY_H
#include <iostream>
#include <string>
#include <exception>

template <typename T>
class Array {
    public:
        Array();
        Array(unsigned int nbrElement);
        Array(Array& copy);
        ~Array();
        Array& operator=(Array& copy);
        int size() const;
        T operator[](unsigned int i);

        class OutOfBounds : public std::exception {
            public:
            const char *what() const throw();
        };
    private:
        T* array;
        unsigned int length;
        


};
#include "Array.tpp"

#endif