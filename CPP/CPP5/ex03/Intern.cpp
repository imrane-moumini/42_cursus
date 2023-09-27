#include "Intern.hpp"

Intern::Intern(){
    std::cout << "Intern default constructor called\n";
}

Intern::Intern(Intern& copy){
    std::cout << "Intern copy constructor called\n";
    (void)copy;
}

Intern& Intern::operator=(Intern& copy){
    std::cout << "Intern operator assignement called\n";
    (void)copy;
    return (*this);
}

Intern::~Intern(){
    std::cout << "Intern destructor called\n";
}
const char* Intern::NoForm::what() const throw(){
    return ("EXCEPTION : NO FORM IS NAMED LIKE THIS");
}

AForm* Intern::makeForm(std::string formName, std::string target){
    const std::string tab[3] = {"Shrubbery Creation", "Presidential Pardon", "Robotomy Request"};
    
    int i = 0;
    ShrubberyCreationForm* sh;
    PresidentialPardonForm* pr;
    RobotomyRequestForm* ro;
    while((formName != tab[i]) && i < 3)
        i++;
    switch (i)
    {
        case 0:
            try{
                sh = new ShrubberyCreationForm(target);
            }catch (const std::bad_alloc& e) {
                std::cerr << "Bad allocation : " << e.what() << std::endl;
            }
            return (sh);

        case 1:
            try{
                pr = new PresidentialPardonForm(target);
            }catch (const std::bad_alloc& e) {
                std::cerr << "Bad allocation : " << e.what() << std::endl;
            }
            return (pr);

         case 2:
            try{
                ro = new RobotomyRequestForm(target);
            }catch (const std::bad_alloc& e) {
                std::cerr << "Bad allocation : " << e.what() << std::endl;
            }
            return (ro);      
        default:
            throw NoForm();
            break;
    }
    return (NULL);
}