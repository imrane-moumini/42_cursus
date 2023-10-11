#include "Array.hpp"


int main(void)
{
    
    Array<int> array(10);
    try {
        std::cout << array[0] << std::endl;
    } catch (Array<int>::OutOfBounds& obj)
    {
        std::cout << obj.what();
    }

    
    

}