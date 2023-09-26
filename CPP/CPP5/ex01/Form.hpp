#ifndef FORM_H
#define FORM_H
#include "Bureaucrat.hpp"

// demander pk cette ligne nécessaire
class Bureaucrat;

class Form {

    public:
    Form();
    Form(std::string const name, int const grade);
    Form(Form& copy);
    Form& operator=(Form& copy);
    ~Form();
    const std::string  getName() const;
    bool getSigne() const ;
    int getGrade() const;
    void beSigned(Bureaucrat& obj);
    

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
std::ostream& operator<<(std::ostream& out, const Form& obj);
#endif