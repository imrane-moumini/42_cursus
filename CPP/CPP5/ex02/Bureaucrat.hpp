#ifndef BUREAUCRAT_H
#define BUREAUCRAT_H
#include <iostream>
#include <string>
#include <exception>
#include "AForm.hpp"

// demander pk cette ligne nécessaire
class AForm; 

class Bureaucrat {
    public:
    Bureaucrat();
    Bureaucrat(std::string const name, int grade);
    Bureaucrat(Bureaucrat& copy);
    Bureaucrat& operator=(Bureaucrat& copy);
    ~Bureaucrat();
    std::string const getName() const;
    int getGrade() const;
    void incrGrade();
    void decrGrade();
    void signForm(AForm& obj);
    void executeForm(AForm const & form);

    class GradeTooHighException : public std::exception {
        public:
        const char* what() const throw();
    };

    class GradeTooLowException : public std::exception {
        public:
        const char* what() const throw();
    };


    private:
    std::string const name;
    int grade; // 1 to 150 highest to lowest

};

std::ostream& operator<<(std::ostream &out, const Bureaucrat&  obj);

#endif