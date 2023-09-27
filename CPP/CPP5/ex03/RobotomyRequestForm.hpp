#ifndef ROBOTOMYREQUESTFORM_H
#define ROBOTOMYREQUESTFORM_H
#include "AForm.hpp"
class Bureaucrat;

class RobotomyRequestForm : public AForm {
    public:
    RobotomyRequestForm();
    RobotomyRequestForm(std::string target);
    RobotomyRequestForm(RobotomyRequestForm& copy);
    RobotomyRequestForm& operator=(RobotomyRequestForm& copy);
    ~RobotomyRequestForm();
    void execute(Bureaucrat const & executor);
    
    private:
    std::string target;
};
#endif