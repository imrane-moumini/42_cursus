#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5), target("Default name"){
    std::cout << "PresidentialPardonForm default constructor called\n";
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 25, 5), target(target){
    std::cout << "PresidentialPardonForm argument constructor called\n";
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm& copy) : AForm(copy), target(copy.target){
    std::cout << "PresidentialPardonForm copy constructor called\n";

}

PresidentialPardonForm& PresidentialPardonForm::operator=(PresidentialPardonForm& copy) {
    std::cout << "PresidentialPardonForm assignment operator  called\n";
    if (this != &copy)
    {
        this->target = copy.target;
        this->setSigne();
    }
    return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm(){
    std::cout << "PresidentialPardonForm destructor called\n";
}

void PresidentialPardonForm::execute(Bureaucrat const & bur){
    if ((bur.getGrade() <= this->getExecGrade()) && this->getSigne())
            std::cout << this->target << " has been pardoned by Zaphod Beeblebrox.\n";
    else
        throw AForm::AFormCantExcecute();
}