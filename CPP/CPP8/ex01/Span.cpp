#include "Span.hpp"

Span::Span(unsigned int N) : maxElement(N), nbrElementInVec(0){
    std::cout << "Default constructor called \n";
}

Span::Span(const Span& copy) : maxElement(copy.maxElement), nbrElementInVec(copy.nbrElementInVec), vec(copy.vec){
    std::cout << "copy constructor called \n";
}

Span& Span::operator=(const Span& copy) {
    std::cout << "assignement operator called \n";
    vec = copy.vec;
    maxElement = copy.maxElement;
    nbrElementInVec = copy.nbrElementInVec;
    return (*this);
}

Span::~Span() {
    std::cout << "destructor called \n";
}

const char* Span::FullVect::what() const throw() {
    return ("EXCEPTION : Span is already full\n");
}

void Span::addNumber(int nbr){
    if (nbrElementInVec < maxElement)
    {
        vec.push_back(nbr);
        nbrElementInVec++;
    }
    else
        throw FullVect();
}

int Span::shortestSpan(){
    int ret = INT_MAX;
	int prev;
    std::vector<int> tmp = vec;
    if (nbrElementInVec <= 0)
    {
        std::cout << "Span is empty\n";
        return (-1);
    }
    if (nbrElementInVec < 2)
    {
        std::cout << "Span need more than 1 element\n";
        return (-1);
    }
    std::sort(tmp.begin(), tmp.end());
    for (std::vector<int>::iterator iter = tmp.begin(); iter != tmp.end(); iter++) 
	{
		if (iter == tmp.begin()) 
			prev = *iter;
		else 
		{
			if (ret > *iter - prev) 
				ret = *iter - prev;
			prev = *iter;
		}
	}
	return (ret);
}

int Span::longestSpan(){
    std::vector<int>::iterator itmin;
    std::vector<int>::iterator itmax;
    itmin = std::min_element(vec.begin(), vec.end());
    itmax = std::max_element(vec.begin(), vec.end());
    if (nbrElementInVec <= 0)
    {
        std::cout << "Span is empty\n";
        return (-1);
    }
    if (nbrElementInVec < 2)
    {
        std::cout << "Span need more than 1 element\n";
        return (-1);
    }
    
    return (*itmax - *itmin);
}