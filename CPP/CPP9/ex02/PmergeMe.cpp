#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{

}
PmergeMe::PmergeMe(PmergeMe& copy)
{
    (void)copy;
}
PmergeMe& PmergeMe::operator=(PmergeMe& copy)
{
    (void)copy;
    return (*this); 
}
PmergeMe::~PmergeMe()
{

}

void PmergeMe::fordJohnsonSort(std::vector<int>& arr)
{
    int left = 0;
    int right = arr.size() - 1;

    while (left < right) {
        int minIndex = left;
        int maxIndex = right;

        for (int i = left; i <= right; ++i) {
            if (arr[i] < arr[minIndex]) {
                minIndex = i;
            }
            if (arr[i] > arr[maxIndex]) {
                maxIndex = i;
            }
        }

        std::swap(arr[left], arr[minIndex]);

        // If the maximum value was at the position of the minimum value after the swap
        if (minIndex == right) {
            std::swap(arr[left], arr[maxIndex]);
        } else {
            std::swap(arr[right], arr[maxIndex]);
        }

        left++;
        right--;
    }
}
void PmergeMe::fordJohnsonSort(std::deque<int>& dq)
{
    int left = 0;
    int right = dq.size() - 1;

    while (left < right) {
        int minIndex = left;
        int maxIndex = right;

        for (int i = left; i <= right; ++i) {
            if (dq[i] < dq[minIndex]) {
                minIndex = i;
            }
            if (dq[i] > dq[maxIndex]) {
                maxIndex = i;
            }
        }

        std::swap(dq[left], dq[minIndex]);

        if (minIndex == right) {
            std::swap(dq[left], dq[maxIndex]);
        } else {
            std::swap(dq[right], dq[maxIndex]);
        }

        left++;
        right--;
    }
}