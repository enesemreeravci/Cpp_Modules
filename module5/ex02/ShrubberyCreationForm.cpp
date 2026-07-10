#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& newTarget) : AForm("ShrubberyCreationForm", 145, 137), target(newTarget) 
{
    std::cout << "ShrubberyCreationForm constructor is called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& copy) : AForm(copy), target(copy.target)
{
    std::cout << "ShrubberyCreationForm is copied" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
    std::cout << "ShrubberyCreationForm destructor is called" << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& rhs)
{
    if(this != &rhs)
    {
        AForm::operator=(rhs);
        target = rhs.target;
    }
    return *this;
}

