#ifndef FORM_H
#define FORM_H
#include "Bureaucrat.hpp"
#include <string>
#include <iostream>
#include <cstring>
#include <fstream>
// demander pk cette ligne nécessaire
class Bureaucrat;

class AForm {

    public:
    AForm();
    AForm(std::string const name, int const grade);
    AForm(AForm& copy);
    AForm& operator=(AForm& copy);
    ~AForm();
    const std::string  getName() const;
    bool getSigne() const ;
    int getGrade() const;
    void beSigned(Bureaucrat& obj);
    void setSigne();
    

    class GradeTooHighException : std::exception {
        public:
        const char* what() const throw();
    };
    class GradeTooLowException : std::exception {
        public:
        const char* what() const throw();
    };

    private:
    const std::string  name;
    bool signe;
    const int  grade;
};
std::ostream& operator<<(std::ostream& out, const AForm& obj);
#endif