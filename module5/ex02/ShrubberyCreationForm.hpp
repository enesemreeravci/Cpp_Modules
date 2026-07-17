#ifndef SHRUBERRY_CREATION_FORM_HPP
#define SHRUBERRY_CREATION_FORM_HPP

#include <iostream>
#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
    private:    
        std::string target;

    public:
        ShrubberyCreationForm(const std::string& newTarget);
        ShrubberyCreationForm(const ShrubberyCreationForm& copy);
        ShrubberyCreationForm& operator=(const ShrubberyCreationForm& rhs);
        ~ShrubberyCreationForm();

        void execute(const Bureaucrat& executor) const; // override
};

#endif