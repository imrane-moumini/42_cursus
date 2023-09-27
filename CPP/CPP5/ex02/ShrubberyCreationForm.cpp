#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 72, 45), target("Default name"){
    std::cout << "ShrubberyCreationForm default constructor called\n";
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 72, 45), target(target){
    std::cout << "ShrubberyCreationForm argument constructor called\n";
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm& copy) : AForm(copy), target(copy.target){
    std::cout << "ShrubberyCreationForm copy constructor called\n";

}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(ShrubberyCreationForm& copy) {
    std::cout << "ShrubberyCreationForm assignment operator  called\n";
    if (this != &copy)
    {
        this->target = copy.target;
        this->setSigne();
    }
    return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm(){
    std::cout << "ShrubberyCreationForm destructor called\n";
}

void ShrubberyCreationForm::execute(Bureaucrat const & bur){
    if ((bur.getGrade() <= this->getExecGrade()) && this->getSigne())
    {
        std::ofstream Outfile(this->target.c_str());
        if (Outfile.fail())
        {
            std::cout << "cannot create the file that your provied please check the filename\n";
            return ;
        }
        Outfile << "                           %                         %\n\
            @@@     %    @@     @@@@                                  *\n\
                @@ %     @  %   @   %          %               ;      ***\n\
                 @@    @      @                               #     *****\n\
             @@@   @@@@@  @@@@@@___    %         %           {###}  *******\n\
                @-@  @   @      @@@@       %               <## ####>********\n\
              @@@@@   @ @         @@@@@               %      {###}***********\n\
                %  @  @@ /@@@@@                          <###########> *******\n\
                    @-@@@@    V     %          %           {#######}******* ***\n\
              %       @@      v        { }             <###############>*******\n\
                      @@               {^^,               {## ######}***** ****\n\
              %      @@     %          (   `-;       <###################> ****\n\
                     @@           _     `;;~~           {#############}********\n\
                     @@   %      /(______);        <################  #####>***\n\
               %     @@@        (         (           {##################}*****\n\
                      @@@        |:------( )     <##########################>**\n\
             @@@@     @@@      _//       / /        {###   ##############}*****\n\
            @@@@@@@  @@@@@    / /@@@@@@@@@ vv  <##############################>\n\
            @@@@@@@ @@@@@@@ @@@@@@@@@@@@@@@@@@@       @@@@@@  @@@@@@@  @@@@\n\
            @@@@@@###@@@@@### @@@@@@@@@@@@@@@@@@ @@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n\
            @@@@@@@@###@##@@ @@@@@@@@@@@@@@@@@@@@@ @@@@@   @@@@@@@@@@@@@@@@@@@\n\
            @@@@@@@@@@@### @@@@@@@@@@@@@@@@@@@@@@@@@@ @@@@@@@@@@@@@@@@@@@@@@@@\n\
            -@@@@@@@@@#####@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@" << std::endl;
        Outfile.close();
    }
    else
        throw AForm::AFormNotSigned();
}