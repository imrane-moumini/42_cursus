#include "AForm.hpp"

AForm::AForm() : name("default name"), signe(false), grade(150) {
    std::cout << "AForm default constructor called \n";
}

AForm::AForm(std::string const name, int const grade) : name(name), signe(false), grade(grade) {
    std::cout << "AForm param constructor called \n";
    if (grade > 150)
        throw AForm::GradeTooHighException();
    if (grade < 1)
        throw AForm::GradeTooLowException();
}

AForm::AForm(AForm& copy) : name(copy.name), signe(copy.signe), grade(copy.grade) {
    std::cout << "AForm copy constructor called \n";
}

AForm& AForm::operator=(AForm& copy){
    std::cout << "AForm assigned operator constructor called \n";
    if (this != &copy)
        signe = copy.signe;
    return (*this);
}

AForm::~AForm(){
    std::cout << " AForm destructor called \n";
}

const std::string AForm::getName() const {
    return (name);
}

bool AForm::getSigne() const {
    return (signe);
}
int  AForm::getGrade() const {
    return (grade);
}

void AForm::beSigned(Bureaucrat& obj){
    if (obj.getGrade() <= grade)
        signe = true;
    else
        throw AForm::GradeTooLowException();
}

const char* AForm::GradeTooHighException::what() const throw(){
    return ("EXCEPTION AForm : Grade is too high \n");
}

const char* AForm::GradeTooLowException::what() const throw(){
    return ("EXCEPTION AForm : Grade is too Low \n");
}


void AForm::setSigne(){
    signe = false;
}

std::ostream& operator<<(std::ostream& out, const AForm& obj){
    out << "AForm name : " << obj.getName() << " AForm signe: " << obj.getSigne() << " AForm grade: " << obj.getGrade() << std::endl;
    return (out);
}



