#include "Serializer.hpp"

Serializer::Serializer(){
    std::cout << "Default Serializer called\n";
}

Serializer::Serializer(Serializer& copy ){
    std::cout << "Copy Serializer called\n";
    (void)copy;
}

Serializer& Serializer::operator=(Serializer& copy ){
    std::cout << "assignement operator Serializer called\n";
    (void)copy;
    return (*this);
}

Serializer::~Serializer(){
    std::cout << "Destructor Serializer called\n";
}

uintptr_t Serializer::Serialize(Data* ptr){
    return (reinterpret_cast<uintptr_t>(ptr));
}

Data* Serializer::deserialize(uintptr_t raw){
    return (reinterpret_cast<Data*>(raw));
}