#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string& newTarget) : AForm("PresidentialPardonForm", 25, 5), target(newTarget)
{
    std::cout << "PresidentialPardonForm constructor is called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& copy) : AForm(copy), target(copy.target)
{
    std::cout << "PresidentialPardonForm is copied" << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& rhs)
{
    if(this != &rhs)
    {
        AForm::operator=(rhs);
        target = rhs.target;
    }
    std::cout << "PresidentialPardonForm is assigned" << std::endl;
    return *this; 
}

PresidentialPardonForm::~PresidentialPardonForm()
{
    std::cout << "PresidentialPardonForm is destructed" << std::endl; 
}

void PresidentialPardonForm::execute(const Bureaucrat& executor) const
{
    if(!getIsSigned())
        throw NotSignedException();
    if(executor.getGrade() > grade_e)
        throw GradeTooLowException();
    
    std::cout << target
              << " has been pardoned by Zaphod Beeblebrox."
              << std::endl;
}