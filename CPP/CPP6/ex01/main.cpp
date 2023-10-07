#include "Serializer.hpp"

int main(void)
{
    Serializer obj;
    Data* ptr = new Data;
    ptr->nbr = 1;
    std::cout << "original ptr is " << ptr << std::endl;
    std::cout << "original ptr value is " << ptr->nbr << std::endl;
    std::cout << "ptr is " << obj.deserialize(obj.Serialize(ptr)) << std::endl;
    std::cout << "ptr value is " << (obj.deserialize(obj.Serialize(ptr)))->nbr << std::endl;
}