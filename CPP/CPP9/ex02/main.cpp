#include "PmergeMe.hpp"

void fordJohnsonSort(std::deque<int>& dq) {
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

void fordJohnsonSort(std::vector<int>& arr) {
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
int main(int argc, char *argv[])
{
    if (argc < 3) {
		std::cout << "Wrong number of arguments.\n";
		return (1);
	}

    std::vector<int>	vector;
	std::deque<int>		deque;

    	for (int i = 1; i < argc; i++) {
		    for (int j = 0; argv[i][j]; j++) {
		    	if (!isdigit(argv[i][j])) {
		    		std::cout << "Error: bad input.\n";
		    		return (1);
		    	}
		    }
		    int num = atoi(argv[i]);
		    if (num < 0) {
		    	std::cout << "Error: bad input.\n";
		    	return (1);
		    }
		    deque.push_back(num);
		    vector.push_back(num);
	    }
	
	std::cout << "Vector Before:	";
	for (size_t i = 0; i < vector.size(); i++)
		std::cout << vector[i] << " ";
	std::cout << '\n';

    clock_t start = std::clock();
	fordJohnsonSort(vector);
	clock_t end = std::clock();
	double time_vector = 1000000.0 * (end - start) / CLOCKS_PER_SEC;

	std::cout << "Vector After:	";
	for (size_t i = 0; i < vector.size(); i++)
		std::cout << vector[i] << " ";
	std::cout << '\n';
	std::cout << '\n';
	std::cout << "Time to process a range of " << vector.size() << " elements with std::vector : " << time_vector << " us\n";


    std::cout << "---------------------------------\n";
    std::cout << "deque Before:	";
	for (size_t i = 0; i < deque.size(); i++)
		std::cout << deque[i] << " ";
	std::cout << '\n';


    clock_t start_deque = std::clock();
	fordJohnsonSort(deque);
	clock_t end_deque = std::clock();
	double time_deque = 1000000.0 * (end_deque - start_deque) / CLOCKS_PER_SEC;

    std::cout << "deque After:	";
	for (size_t i = 0; i < deque.size(); i++)
		std::cout << deque[i] << " ";
	std::cout << '\n';
	std::cout << '\n';

    std::cout << "Time to process a range of " << vector.size() << " elements with std::deque : " << time_deque << " us\n";

}