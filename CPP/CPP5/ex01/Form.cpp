#include "Form.hpp"

Form::Form() : name("default name"), signe(false), grade(150) {
    std::cout << "Form default constructor called \n";
}

Form::Form(std::string const name, int const grade) : name(name), signe(false), grade(grade) {
    std::cout << "Form param constructor called \n";
    if (grade > 150)
        throw Form::GradeTooHighException();
    if (grade < 1)
        throw Form::GradeTooLowException();
}

Form::Form(Form& copy) : name(copy.name), signe(copy.signe), grade(copy.grade) {
    std::cout << "Form copy constructor called \n";
}

Form& Form::operator=(Form& copy){
    std::cout << "Form assigned operator constructor called \n";
    if (this != &copy)
        signe = copy.signe;
    return (*this);
}

Form::~Form(){
    std::cout << " Form destructor called \n";
}

const std::string Form::getName() const {
    return (name);
}

bool Form::getSigne() const {
    return (signe);
}
int  Form::getGrade() const {
    return (grade);
}

void Form::beSigned(Bureaucrat& obj){
    if (obj.getGrade() <= grade)
        signe = true;
    else
        throw Form::GradeTooLowException();
}

const char* Form::GradeTooHighException::what() const throw(){
    return ("Form : Grade is too high \n");
}

const char* Form::GradeTooLowException::what() const throw(){
    return ("Form : Grade is too high \n");
}

std::ostream& operator<<(std::ostream& out, const Form& obj){
    out << "Form name : " << obj.getName() << " Form signe: " << obj.getSigne() << " Form grade: " << obj.getGrade() << std::endl;
    return (out);
}



