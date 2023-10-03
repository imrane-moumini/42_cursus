#include "ScalarConverter.hpp"
#include <iomanip>

void ScalarConverter::convert(std::string str){
  
    double nbrD;
    float nbrF;
    int nbrI;
    char nbrC;

    if (!(str.c_str()[0] <= '0' && str.c_str()[0] <= '9') && (str.c_str()[1]) && !(str.c_str()[1] <= '0' && str.c_str()[1] >= '9'))
    {
        printNotNumb(str);
        return ;
    }
    if (!(str.c_str()[0] <= '0' && str.c_str()[0] <= '9') && !(str.c_str()[1]))
    {
        printLetter(str);
        return ;
    }
    if (!(str.find('.')))
    {
        nbrD = std::atof(str.c_str());
        nbrF = static_cast<float>(nbrD);
        nbrI = static_cast<int>(nbrD);
        nbrC = nbrI;

        std::cout << "char: " << nbrC << std::endl;
        std::cout << "int: " << nbrI << std::endl;
        std::cout << "float: " <<  std::fixed  << std::setprecision(1) << nbrF << 'f' <<std::endl;
        std::cout << "double: " <<  std::fixed  << std::setprecision(1) << nbrD << std::endl;
    }
    else
    {
        int count;
       
        count = nbrElementAfterPoint(str.c_str());
        nbrD = std::atof(str.c_str());
        nbrF = static_cast<float>(nbrD);
        nbrI = static_cast<int>(nbrD);
        nbrC = nbrI;

        std::cout << "char: " << nbrC << std::endl;
        std::cout << "int: " << nbrI << std::endl;
        std::cout << "float: " <<  std::fixed  << std::setprecision(count) << nbrF << 'f' <<std::endl;
        std::cout << "double: " <<  std::fixed  << std::setprecision(count) << nbrD << std::endl;
         
    }
}