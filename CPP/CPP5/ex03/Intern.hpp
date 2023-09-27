#ifndef INTERN_H
#define INTERN_H
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"


class Intern {
    public:
    Intern();
    Intern(Intern& copy);
    Intern& operator=(Intern& copy);
    ~Intern();
    AForm* makeForm(std::string formName, std::string target);

    class NoForm : public std::exception {
        public:
        const char *what() const throw();
    };

};
#endif