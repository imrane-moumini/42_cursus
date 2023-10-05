#include "ScalarConverter.hpp"
#include <iomanip>
int	isPrint(int c)
{
    if (c < 0)
    {
        return (0);
    }
	if (!(c >= 0 && c <= 31) && (c <= 126))
	{
		return (1);
	}
	return (0);
}

void printLetter(std::string str)
{
    double nbrD;
    float nbrF;
    int nbrI;
    
    nbrI = str.c_str()[0];
    nbrF = nbrI;
    nbrD = nbrI;
    if (isPrint(nbrI))
        std::cout << "char: " << str.c_str()[0] << std::endl;
    else
        std::cout << "char: " << "Non displayable\n";
    std::cout << "int: " << nbrI << std::endl;
    std::cout << "float: " <<  std::fixed  << std::setprecision(1) << nbrF << 'f' <<std::endl;
    std::cout << "double: " <<  std::fixed  << std::setprecision(1) << nbrD << std::endl;
}


void minusInff()
{
    std::cout << "char: " << "impossible"<< std::endl;
    std::cout << "int: " << "impossible"<< std::endl;
    std::cout << "float: " << "-inff" << std::endl;
    std::cout << "double: " << "-inf" << std::endl;
}

void plusInff()
{
    std::cout << "char: " << "impossible"<< std::endl;
    std::cout << "int: " << "impossible"<< std::endl;
    std::cout << "float: " << "inff" << std::endl;
    std::cout << "double: " << "inf" << std::endl;
}

void nanFloFunction()
{
    std::cout << "char: " << "impossible"<< std::endl;
    std::cout << "int: " << "impossible"<< std::endl;
    std::cout << "float: " << "nanf" << std::endl;
    std::cout << "double: " << "nan" << std::endl;
}

void printNotNumb(std::string str)
{
    std::string tab[6] = {"-inff", "+inff", "nanf", "-inf", "+inf", "nan"};
    void (*f[6])() = {minusInff, plusInff, nanFloFunction, minusInff, plusInff, nanFloFunction};
    for (int i = 0; i < 6; i++)
    {
        if (str == tab[i])
        {
            f[i]();
            return ;
        }
    }
    std::cout << "char: " << "impossible"<< std::endl;
    std::cout << "int: " << "impossible"<< std::endl;
    std::cout << "float: " << "impossible" << std::endl;
    std::cout << "double: " << "impossible" << std::endl;
}
int nbrElementAfterPoint(const char *str)
{
    int count;
    int i;

    i = 0;
    count = 0;
    while (str[i] )
    {
        if (str[i] == '.')
        {
            i++;
            while (str[i] && str[i] >= '0' && str[i] <= '9')
            {
                count++;
                i++;
            }
            return (count);
        }
        i++;
    }
    return (count);

}

int moreThanOnePoint(std::string str)
{
    int nombreOccurrences = 0;
    size_t pos = str.find('.');
    while (pos != std::string::npos)
    {
        nombreOccurrences++;
        pos = str.find('.', pos + 1);
    }
    if (nombreOccurrences > 1)
    {
        std::cout << "char: " << "impossible"<< std::endl;
        std::cout << "int: " << "impossible"<< std::endl;
        std::cout << "float: " << "impossible" << std::endl;
        std::cout << "double: " << "impossible" << std::endl;
        return (1);
    }
    return (0);
}
int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        std::cout << "wrong number of argument \n";
        return (1);
    }
    ScalarConverter::convert(argv[1]);
    // c'est presque ça, faire des test et ajuster
}