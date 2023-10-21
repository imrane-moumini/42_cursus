#ifndef MUTANT_H
#define MUTANT_H


#include <algorithm>
#include <stack>
#include <vector>
#include <iostream>
#include <string>
#include <iterator>
#include <deque>
#include <climits>
#include <list>
#include <exception>

template <typename T>
class MutantStack : public std::stack<T> {
    public:
    MutantStack();
    MutantStack(MutantStack& copy);
    MutantStack& operator=(MutantStack& copy);
    ~MutantStack();

    typedef typename MutantStack<T>::stack::container_type::iterator iterator;
	typedef typename MutantStack<T>::stack::container_type::reverse_iterator reverse_iterator;
	typedef typename MutantStack<T>::stack::container_type::const_iterator const_iterator;
	typedef typename std::stack<T>::container_type::const_reverse_iterator	const_reverse_iterator; 

    iterator				begin();
	iterator				end();
	reverse_iterator		rbegin();
	reverse_iterator		rend();
	const_iterator			cbegin() const;
	const_iterator			cend() const;
	const_reverse_iterator	crbegin() const;
	const_reverse_iterator	crend() const;
};

#include "MutantStack.tpp"
#endif