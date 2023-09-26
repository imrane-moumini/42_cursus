#include "Bureaucrat.hpp"
#include "Form.hpp"

int main (void)
{
    Bureaucrat Alin("Alin", 150);
    
    try {
        Form quizz("quizz", 1);
        std::cout << quizz << std::endl;
        Alin.signForm(quizz);
        std::cout << quizz << std::endl;
    }catch(Form::GradeTooHighException& obj) {
        std::cout << obj.what();
    } catch(Form::GradeTooLowException& obj) {
        std::cout << obj.what();
    }

    std::cout << "------------------------------------\n";

    try {
        Form quizz("quizz", 150);
        Alin.signForm(quizz);
    }catch(Form::GradeTooHighException& obj) {
        std::cout << obj.what();
    } catch(Form::GradeTooLowException& obj) {
        std::cout << obj.what();
    }
    std::cout << "------------------------------------\n";

    try {
        Form quizz("quizz", 160);
        Alin.signForm(quizz);
    }catch(Form::GradeTooHighException& obj) {
        std::cout << obj.what();
    } catch(Form::GradeTooLowException& obj) {
        std::cout << obj.what();
    }
    std::cout << "------------------------------------\n";
    try {
        Form quizz("quizz", 150);
        Alin.signForm(quizz);
        std::cout << quizz << std::endl;
    }catch(Form::GradeTooHighException& obj) {
        std::cout << obj.what();
    } catch(Form::GradeTooLowException& obj) {
        std::cout << obj.what();
    }

}