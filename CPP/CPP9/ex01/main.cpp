#include "RPN.hpp"

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        std::cout << "wrong number of arguments\n";
        return (1);
    }

    std::stack<int> stack;
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
                result = stack.top();
                stack.pop();
                result = result + stack.top();
                stack.pop();
                stack.push((result));
                break;
            }
            case '-':
            {
                value1 = stack.top();
                stack.pop();
                value2 = stack.top();
                stack.pop();
                result = value2 - value1;
                stack.push((result));
                break;
            }
            case '*':
            {
                result = stack.top();
                stack.pop();
                result = result * stack.top();
                stack.pop();
                stack.push((result));
                break;
            }
            case '/':
            {
                value1 = stack.top();
                stack.pop();
                value2 = stack.top();
                stack.pop();
                result = value2 / value1;
                stack.push((result));
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
    std::cout << stack.top() << std::endl;
}