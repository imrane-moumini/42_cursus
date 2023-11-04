#include "RPN.hpp"

RPN::RPN()
{

}
RPN::RPN(RPN& copy)
{
    std::stack<int> tempStack;
    if (this != &copy)
    {
        while (!copy.stack.empty()) {
            int temp = copy.stack.top();  
            tempStack.push(temp);    
            copy.stack.pop();        
        }

        while (!tempStack.empty()) {
            int temp = tempStack.top(); 
            copy.stack.push(temp);         
            this->stack.push(temp);          
            tempStack.pop();           
        }
    }
}
RPN& RPN::operator=(RPN& copy)
{
    std::stack<int> tempStack;

    if (this != &copy)
    {
        while (!copy.stack.empty()) {
            int temp = copy.stack.top();  
            tempStack.push(temp);    
            copy.stack.pop();        
        }

        while (!tempStack.empty()) {
            int temp = tempStack.top(); 
            copy.stack.push(temp);         
            this->stack.push(temp);          
            tempStack.pop();           
        }
    }
    return (*this);
}
RPN::~RPN()
{

}
int RPN::getTopValue()
{
    return (stack.top());
}
int RPN::algo(char* argv[])
{
    int value1;
    int value2;
    int result;
    std::string car;
    int i = 0;
    while (argv[1][i])
    {
        switch (argv[1][i])
        {
            case '+':
            {
                if (stack.size() >= 2)
                {
                    result = stack.top();
                    stack.pop();
                    result = result + stack.top();
                    stack.pop();
                    stack.push((result));
                }
                else
                {
                    std::cout << "input error\n";
                    return 1;
                }
                break;
            }
            case '-':
            {
                if (stack.size() >= 2)
                {
                    value1 = stack.top();
                    stack.pop();
                    value2 = stack.top();
                    stack.pop();
                    result = value2 - value1;
                    stack.push((result));
                }
                else
                {
                    std::cout << "input error\n";
                    return 1;
                }
                break;
            }
            case '*':
            {
                if (stack.size() >= 2)
                {
                    result = stack.top();
                    stack.pop();
                    result = result * stack.top();
                    stack.pop();
                    stack.push((result));
                }
                else
                {
                    std::cout << "input error\n";
                    return 1;
                }
                break;
            }
            case '/':
            {
                if (stack.size() >= 2)
                {
                    value1 = stack.top();
                    stack.pop();
                    value2 = stack.top();
                    stack.pop();
                    result = value2 / value1;
                    stack.push((result));
                }
                else
                {
                    std::cout << "input error\n";
                    return 1;
                }
                break;
            }

            default:
            {
                if (argv[1][i]  != ' ')
                {
                    car = argv[1][i];
                    stack.push(atoi(car.c_str()));
                }
            }
            
        }
        i++;
    }
    return (0);
}