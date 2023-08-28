#include <string>
#include <iostream>

int main()
{
    std::string brain = "HI THIS IS BRAIN";
    std::string* stringPTR = &brain;
    std::string& stringREF = brain;

    std::cout << "brain  adress is " << &brain << std::endl;
    std::cout << "stringPTR adress is " << stringPTR << std::endl;
    std::cout << "stringREF adress is " << &stringREF << std::endl;
    std::cout << "brain  value is " << brain << std::endl;
    std::cout << "stringPTR value is " << *stringPTR << std::endl;
    std::cout << "stringREF value is " << stringREF << std::endl;





}