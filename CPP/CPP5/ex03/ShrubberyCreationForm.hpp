#ifndef SHRUBBERYCEATIONFORM_H
#define SHRUBBERYCEATIONFORM_H

#include "AForm.hpp"
class Bureaucrat;

class ShrubberyCreationForm : public AForm {
    public:
    ShrubberyCreationForm();
    ShrubberyCreationForm(std::string target);
    ShrubberyCreationForm(ShrubberyCreationForm& copy);
    ShrubberyCreationForm& operator=(ShrubberyCreationForm& copy);
    ~ShrubberyCreationForm();
    void execute(Bureaucrat const & executor);
    
    private:
    std::string target;
};
#endif