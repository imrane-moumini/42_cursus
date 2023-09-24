#include "Bureaucrat.hpp"

int main (void)
{
    Bureaucrat Alin("Alin", 150);
    try {
        Alin.decrGrade();
    } catch(Bureaucrat::GradeTooHighException& obj) {
        std::cout << obj.what();
    }
    catch(Bureaucrat::GradeTooLowException& obj) {
        std::cout << obj.what();
    }
    std::cout << Alin << std::endl; 

}