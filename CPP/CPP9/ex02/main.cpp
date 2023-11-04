#include "PmergeMe.hpp"
bool hasDuplicates(const std::vector<int>& vec) {
    std::set<int> encountered;

    for (std::vector<int>::const_iterator it = vec.begin(); it != vec.end(); ++it) {
        if (encountered.find(*it) != encountered.end()) {
            return true; // Found a duplicate
        } else {
            encountered.insert(*it);
        }
    }

    return false; // No duplicates found
}

int main(int argc, char *argv[])
{
    if (argc < 3) {
		std::cout << "Wrong number of arguments.\n";
		return (1);
	}
    PmergeMe p;
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
	if (hasDuplicates(vector))
	{
		std::cout << "input can't have duplicates elements\n";
		return (1);
	}
	std::cout << "Vector Before:	";
	for (size_t i = 0; i < vector.size(); i++)
		std::cout << vector[i] << " ";
	std::cout << '\n';

    clock_t start = std::clock();
	p.fordJohnsonSort(vector);
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
	p.fordJohnsonSort(deque);
	clock_t end_deque = std::clock();
	double time_deque = 1000000.0 * (end_deque - start_deque) / CLOCKS_PER_SEC;

    std::cout << "deque After:	";
	for (size_t i = 0; i < deque.size(); i++)
		std::cout << deque[i] << " ";
	std::cout << '\n';
	std::cout << '\n';

    std::cout << "Time to process a range of " << vector.size() << " elements with std::deque : " << time_deque << " us\n";

}