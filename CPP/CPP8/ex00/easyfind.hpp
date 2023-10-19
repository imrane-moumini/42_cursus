#ifndef EASYFIND_H
#define EASYFIND_H
#include <algorithm>
#include <vector>
#include <iostream>
#include <string>
#include <iterator>
#include <deque>
#include <list>

template <typename T>
int easyfind(T intContainer, int nbr){
// t un container de int
// donc je pense que ça doit être nptk quelle container mas qui va prendre un int
// la fonction doit trouver la première occurence du second param dans le premier param
// donc en gros g 3 en second paramete, ya pliens de chiffre dans le premier
// si je toruve 3 c'est bon (j'affiche un messaghe genre trouvé)
// si je trouve pas 3 je renvoi une execption
    typename T::iterator it = find(intContainer.begin(), intContainer.end(), nbr);
    if (it != intContainer.end())
    {
        std::cout << "the number is in the Container\n";
        return (1);
    }
    else
        std::cout << "the number is NOT in the Container\n";
    return (-1);
}

#endif