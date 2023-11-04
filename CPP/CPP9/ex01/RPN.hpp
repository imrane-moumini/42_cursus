#ifndef RPN_H
#define RPN_H

#include <iostream>
#include <string>
#include <algorithm>
#include <stack>
class RPN {
    public:
        RPN();
        RPN(RPN& copy);
        RPN& operator=(RPN& copy);
        ~RPN();
        int getTopValue();
        int algo(char* argv[]);

    private:
        std::stack<int> stack;

};
#endif