#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

int main (void)
{
    //MASQUER TYPE PAR TYPE PENDANT CORRECT POUR CAPTER LES MESSAGES
  //Shrubby Form TEST
 //Required grades: sign 145, exec 137
 /*
    {
        Bureaucrat opti("OPTI", 1);
        Bureaucrat dead("DEAD", 150);
        Bureaucrat excecoff("EXCECOFF", 138);
        std::cout << "                         SHRUBBY FORM TEST                \n";
        std::cout << "\n";
        
        try{
            std::cout << "XXXXXXXXXXXXXXXXXXXXXXXXOPTIXXXXXXXXXXXXXXXXXXXXXXXXX\n";
            ShrubberyCreationForm a;
            std::cout << "\n";
            a.beSigned(opti);
            a.execute(opti);
            opti.executeForm(a);
            std::cout << "\n";
        }
        catch (AForm::AFormCantExcecute& obj){
            std::cout << obj.what() << std::endl;
            std::cout << "\n";
        }

        try{
            std::cout << "XXXXXXXXXXXXXXXXXXXXXXXXDEADXXXXXXXXXXXXXXXXXXXXXXXXX\n";
            ShrubberyCreationForm b("b");
            std::cout << "\n";
            b.beSigned(dead);
            b.execute(dead);
            std::cout << "\n";
        }
        catch (AForm::GradeTooLowException& obj){
            std::cout << obj.what() << std::endl;
            std::cout << "\n";
        }

        try{
            std::cout << "XXXXXXXXXXXXXXXXXXXXXXXXEXCECOFFXXXXXXXXXXXXXXXXXXXXXXXXX\n";
            ShrubberyCreationForm c("b");
            std::cout << "\n";
            c.beSigned(excecoff);
            c.execute(excecoff);
            std::cout << "\n";
        }
        catch (AForm::AFormCantExcecute& obj){
            std::cout << obj.what() << std::endl;
            std::cout << "\n";
        }






        std::cout << "\n";
        std::cout << "\n";
        std::cout << "\n";
        std::cout << "-----------------------------------\n";
    }
*/



  //Robo Form Test
  //Required grades: sign 72, exec 45
  /*
    {
        Bureaucrat opti("OPTI", 1);
        Bureaucrat dead("DEAD", 150);
        Bureaucrat excecoff("EXCECOFF", 46);
        std::cout << "                         ROBO FORM TEST                \n";
        std::cout << "\n";
        
        try{
            std::cout << "XXXXXXXXXXXXXXXXXXXXXXXXOPTIXXXXXXXXXXXXXXXXXXXXXXXXX\n";
            RobotomyRequestForm a;
            std::cout << "\n";
            a.beSigned(opti);
            a.execute(opti);
            opti.executeForm(a);
            std::cout << "\n";
        }
        catch (AForm::AFormCantExcecute& obj){
            std::cout << obj.what() << std::endl;
            std::cout << "\n";
        }

        try{
            std::cout << "XXXXXXXXXXXXXXXXXXXXXXXXDEADXXXXXXXXXXXXXXXXXXXXXXXXX\n";
            RobotomyRequestForm b("b");
            std::cout << "\n";
            b.beSigned(dead);
            b.execute(dead);
            std::cout << "\n";
        }
        catch (AForm::GradeTooLowException& obj){
            std::cout << obj.what() << std::endl;
            std::cout << "\n";
        }

        try{
            std::cout << "XXXXXXXXXXXXXXXXXXXXXXXXEXCECOFFXXXXXXXXXXXXXXXXXXXXXXXXX\n";
            RobotomyRequestForm c("b");
            std::cout << "\n";
            c.beSigned(excecoff);
            c.execute(excecoff);
            std::cout << "\n";
        }
        catch (AForm::AFormCantExcecute& obj){
            std::cout << obj.what() << std::endl;
            std::cout << "\n";
        }






        std::cout << "\n";
        std::cout << "\n";
        std::cout << "\n";
        std::cout << "-----------------------------------\n";
    }
    */




  //President Form test
  // Required grades: sign 25, exec 5
   {
        Bureaucrat opti("OPTI", 1);
        Bureaucrat dead("DEAD", 150);
        Bureaucrat excecoff("EXCECOFF", 6);
        std::cout << "                         PRES FORM TEST                \n";
        std::cout << "\n";
        
        try{
            std::cout << "XXXXXXXXXXXXXXXXXXXXXXXXOPTIXXXXXXXXXXXXXXXXXXXXXXXXX\n";
            PresidentialPardonForm a;
            std::cout << "\n";
            a.beSigned(opti);
            a.execute(opti);
            opti.executeForm(a);
            std::cout << "\n";
        }
        catch (AForm::AFormCantExcecute& obj){
            std::cout << obj.what() << std::endl;
            std::cout << "\n";
        }

        try{
            std::cout << "XXXXXXXXXXXXXXXXXXXXXXXXDEADXXXXXXXXXXXXXXXXXXXXXXXXX\n";
            PresidentialPardonForm b("b");
            std::cout << "\n";
            b.beSigned(dead);
            b.execute(dead);
            std::cout << "\n";
        }
        catch (AForm::GradeTooLowException& obj){
            std::cout << obj.what() << std::endl;
            std::cout << "\n";
        }

        try{
            std::cout << "XXXXXXXXXXXXXXXXXXXXXXXXEXCECOFFXXXXXXXXXXXXXXXXXXXXXXXXX\n";
            PresidentialPardonForm c("b");
            std::cout << "\n";
            c.beSigned(excecoff);
            c.execute(excecoff);
            std::cout << "\n";
        }
        catch (AForm::AFormCantExcecute& obj){
            std::cout << obj.what() << std::endl;
            std::cout << "\n";
        }






        std::cout << "\n";
        std::cout << "\n";
        std::cout << "\n";
        std::cout << "-----------------------------------\n";
    }
}