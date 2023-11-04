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
    RPN obj;
    if (argc != 2)
    {
        std::cout << "wrong number of arguments\n";
        return (1);
    }

    if (checkError(argv))
    {
        std::cout << "Error\n";
        return (1);
    }
    if (obj.algo(argv) == 1)
        return (1);
    std::cout << obj.getTopValue() << std::endl;
}