#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 145, 137), target("Default name"){
    std::cout << "RobotomyRequestForm default constructor called\n";
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 145, 137), target(target){
    std::cout << "RobotomyRequestForm argument constructor called\n";
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm& copy) : AForm(copy), target(copy.target){
    std::cout << "RobotomyRequestForm copy constructor called\n";

}

RobotomyRequestForm& RobotomyRequestForm::operator=(RobotomyRequestForm& copy) {
    std::cout << "RobotomyRequestForm assignment operator  called\n";
    if (this != &copy)
    {
        this->target = copy.target;
        this->setSigne();
    }
    return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm(){
    std::cout << "RobotomyRequestForm destructor called\n";
}

void RobotomyRequestForm::execute(Bureaucrat const & bur){
    if ((bur.getGrade() <= this->getExecGrade()) && this->getSigne())
    {
        std::cout << "IIIIIIIIIIIIIIIIIIIIIIIIIII\n";
        if (std::rand() % 2)
            std::cout << this->target << " has been robotomized\n";
        else
            std::cout << "robotomy failed\n";
    }
    else
        throw AForm::AFormNotSigned();
}