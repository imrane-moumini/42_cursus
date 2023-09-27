#include "Intern.hpp"

int main (void)
{
   Intern someRandomIntern;
    AForm* rrf;

    try {
        rrf = someRandomIntern.makeForm("Robotomy Request", "Bender");
    } catch (Intern::NoForm& obj){
        std::cout << obj.what() << std::endl;
        return (0);
    }
    std::cout << *rrf << std::endl;
    delete rrf;
}