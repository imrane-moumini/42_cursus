#include "ScalarConverter.hpp"
#include <iomanip>

void ScalarConverter::convert(std::string str){
  
    double nbrD;
    float nbrF;
    int nbrI;
    char nbrC;
    std::cout << "c1\n";
    if (!(str.c_str()[0] >= '0' && str.c_str()[0] <= '9') && (str.c_str()[1]) && !(str.c_str()[1] >= '0' && str.c_str()[1] <= '9'))
    {
        std::cout << "c2\n";
        printNotNumb(str);
        return ;
    }
    if (!(str.c_str()[0] >= '0' && str.c_str()[0] <= '9') && !(str.c_str()[1]))
    {
        std::cout << "c3\n";
        printLetter(str);
        return ;
    }
    if ((str.find('.') == std::string::npos))
    {
        
        std::cout << "c4\n";
        nbrD = std::atof(str.c_str());
        nbrF = static_cast<float>(nbrD);
        nbrI = static_cast<int>(nbrD);
        nbrC = nbrI;

        if (isPrint(nbrI))
            std::cout << "char: " << nbrC << std::endl;
        else
            std::cout << "char: " << "Non displayable\n";
        std::cout << "int: " << nbrI << std::endl;
        std::cout << "float: " <<  std::fixed  << std::setprecision(1) << nbrF << 'f' <<std::endl;
        std::cout << "double: " <<  std::fixed  << std::setprecision(1) << nbrD << std::endl;
    }
    else
    {
        int count;
        std::cout << "c5\n";

        if (moreThanOnePoint(str))
            return ;
        count = nbrElementAfterPoint(str.c_str());
        nbrD = std::atof(str.c_str());
        nbrF = static_cast<float>(nbrD);
        nbrI = static_cast<int>(nbrD);
        nbrC = nbrI;
        if (isPrint(nbrI))
            std::cout << "char: " << nbrC << std::endl;
        else
            std::cout << "char: " << "Non displayable\n";
        std::cout << "int: " << nbrI << std::endl;
        std::cout << "float: " <<  std::fixed  << std::setprecision(count) << nbrF << 'f' <<std::endl;
        std::cout << "double: " <<  std::fixed  << std::setprecision(count) << nbrD << std::endl;
         
    }
}