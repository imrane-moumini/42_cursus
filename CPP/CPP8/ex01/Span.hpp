#ifndef SPAN_H
#define SPAN_H


#include <algorithm>
#include <vector>
#include <iostream>
#include <string>
#include <iterator>
#include <deque>
# include <climits>
#include <list>
#include <exception>
class Span {
    //peut stocker un maximum de N entier
    // je pense que je dois choisir un container et lui passer les N éléments
    // N est un unsigned int
    // N est le seul paramètre passé au constructeur
    public:
    Span(unsigned int N);
    Span(const Span& copy);
    Span& operator=(const Span& copy);
    ~Span();

    void addNumber(int nbr);
    int  shortestSpan();
    int  longestSpan();
    void addRange(std::vector<int>::iterator begin, std::vector<int>::iterator end);

    class FullVect : public std::exception {
        public:
        const char * what() const throw();
    };

    private:
    int maxElement;
    int nbrElementInVec;
    std::vector<int> vec;
    
};
#endif