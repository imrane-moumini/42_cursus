#ifndef SHRUBBERYCEATIONFORM_H
#define SHRUBBERYCEATIONFORM_H

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm {
    public:
    ShrubberyCreationForm();
    ShrubberyCreationForm(std::string target);
    ShrubberyCreationForm(ShrubberyCreationForm& copy);
    ShrubberyCreationForm& operator=(ShrubberyCreationForm& copy);
    ~ShrubberyCreationForm();

    private:
    std::string target;
};
#endif