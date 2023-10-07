#ifndef SERIALIZER_H
#define SERIALIZER_H

#include <iostream>
#include <string>
#include "data.hpp"
#include <stdint.h>

class Serializer {
    public:
    Serializer();
    Serializer(Serializer& copy);
    Serializer& operator=(Serializer& copy);
    ~Serializer();
    uintptr_t Serialize(Data* ptr);
    Data* deserialize(uintptr_t raw);
};
#endif 