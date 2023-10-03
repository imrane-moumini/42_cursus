#ifndef SCALARCONVERTER_H
#define SCALARCONVERTER_H

#include <iostream>
#include <string>
#include <cstdlib>
class ScalarConverter {
    public:
    static void convert(std::string str);

    private:
    ScalarConverter();
    ScalarConverter(ScalarConverter& copy);
    ScalarConverter& operator=(ScalarConverter& copy);
    ~ScalarConverter();



};

int nbrElementAfterPoint(const char *str);
void printNotNumb(std::string str);
void printLetter(std::string str);
#endif