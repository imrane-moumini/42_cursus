#ifndef WHATEVER_H
#define WHATEVER_H
#include <iostream>
#include <string>

template <typename T>
void iter(T *array, int length, void (*f)(T)) {
   for (int i = 0; i < length ;i++)
      f(array[i]);
}

template<typename T>
void print(T value)
{
	std::cout << value << std::endl;
}


#endif