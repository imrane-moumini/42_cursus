#include "easyfind.hpp"

int main(void)
{
    std::cout << "---------------------------VECTOR------------------\n";
    int arr[] = {1, 2, 3, 4, 5};
    int arr2[] = {1, 2, 4, 5};
    std::vector<int> vect(arr, arr + sizeof(arr) / sizeof(arr[0]));
    std::vector<int> vect2(arr2, arr2 + sizeof(arr2) / sizeof(arr2[0]));
    
    easyfind(vect, 3);
    easyfind(vect2, 3);


    std::cout << "---------------------------DEQUE------------------\n";
    std::deque<int> deque(arr, arr + sizeof(arr) / sizeof(arr[0]));
    std::deque<int> deque2(arr2, arr2 + sizeof(arr2) / sizeof(arr2[0]));
    
    easyfind(deque, 3);
    easyfind(deque2, 3);

      std::cout << "---------------------------LIST------------------\n";
    std::list<int> list(arr, arr + sizeof(arr) / sizeof(arr[0]));
    std::list<int> list2(arr2, arr2 + sizeof(arr2) / sizeof(arr2[0]));
    
    easyfind(list, 3);
    easyfind(list2, 3);

   
}