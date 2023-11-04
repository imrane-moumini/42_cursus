#ifndef PMERGEME_H
#define PMERGEME_H

#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <ctime>
#include <string>

class PmergeMe {
    public:
        PmergeMe();
        PmergeMe(PmergeMe& copy);
        PmergeMe& operator=(PmergeMe& copy);
        ~PmergeMe();
        void fordJohnsonSort(std::vector<int>& arr);
        void fordJohnsonSort(std::deque<int>& dq);

};
#endif