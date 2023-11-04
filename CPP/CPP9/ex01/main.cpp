#include "RPN.hpp"
int checkError(char *argv[])
{
    int i = 0;

    while (argv[1][i])
    {
        // si pas chiffres ou espace ou signe
        if (!(argv[1][i] >= '0' && argv[1][i] <= '9'))
        {
            if (argv[1][i] != ' ')
            {
                if (argv[1][i] != '+' && argv[1][i] != '*' && argv[1][i] != '-' && argv[1][i] != '/')
                    return (1);
            }
        }

        i++;
    }
    return (0);
}

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
    if (checkError(argv))
    {
        std::cout << "Error\n";
        return (1);
    }
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
    std::cout << stack.top() << std::endl;
}