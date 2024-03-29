#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("Jonh Doe"), grade(150)
{
    std::cout << "Bureaucrat default constructor called \n";
}

Bureaucrat::Bureaucrat(std::string const name, int grade) : name(name), grade(grade){
    std::cout << "Bureaucrat name constructor called \n";
    if (grade > 150)
    {
        grade = 150;
        throw Bureaucrat::GradeTooHighException();
    }
    if (grade < 1)
    {
        grade = 1;
        throw Bureaucrat::GradeTooLowException();
    }
}

Bureaucrat::Bureaucrat(Bureaucrat& copy) : name(copy.name), grade(copy.grade){
    std::cout << "Bureaucrat copy constructor called \n";
}


Bureaucrat& Bureaucrat::operator=(Bureaucrat& copy){
        std::cout << "Bureaucrat operator constructor called \n";
        if (this != &copy)
            this->grade = copy.grade;
        return (*this);
}

Bureaucrat::~Bureaucrat(){
    std::cout << "Bureaucrat destructor called \n";
}

const char * Bureaucrat::GradeTooHighException::what() const throw(){
    return "EXCEPTION : you can't improve more the grade\n";
}

const char * Bureaucrat::GradeTooLowException::what() const throw(){
    return "EXCEPTION : you can't degrade more the grade\n";
}

int Bureaucrat::getGrade() const {
    return (grade);
}

std::string const Bureaucrat::getName() const {
    return (name);
}

void Bureaucrat::incrGrade(){
    if (grade - 1 <= 0)
        throw Bureaucrat::GradeTooHighException();
    else
        grade--;
}

void Bureaucrat::decrGrade(){
    if (grade + 1 > 150)
        throw Bureaucrat::GradeTooLowException();
    else
        grade++;
}

std::ostream& operator<<(std::ostream &out, const Bureaucrat&  obj)
{
    out << obj.getName() << ", bureaucrate grade "<< obj.getGrade();
    return out;
}

void Bureaucrat::signForm(Form& obj){
    if (this->getGrade() <= obj.getGrade())
    {
        std::cout << this->name << " signed " << obj.getName() << std::endl;
        obj.beSigned(*this);
    }
    else
    {
        std::cout << this->name << " couldn't signed " << obj.getName() << " because he can't right now" << std::endl;
        obj.beSigned(*this);
    }
}