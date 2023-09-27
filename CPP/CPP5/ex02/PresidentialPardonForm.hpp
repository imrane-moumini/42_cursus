#ifndef PRESIDENTIALPARDONFORM_H
#define PRESIDENTIALPARDONFORM_H
#include "AForm.hpp"
class Bureaucrat;

class PresidentialPardonForm : public AForm{
    public:
    PresidentialPardonForm();
    PresidentialPardonForm(std::string target);
    PresidentialPardonForm(PresidentialPardonForm& copy);
    PresidentialPardonForm& operator=(PresidentialPardonForm& copy);
    ~PresidentialPardonForm();
    void execute(Bureaucrat const & executor);
    
    private:
    std::string target;
};
#endif