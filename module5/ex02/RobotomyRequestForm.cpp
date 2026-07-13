#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string& newTarget) : AForm("RobotomyRequestForm", 72, 45), target(newTarget)
{
    std::cout << "RobotomyRequestForm constructor is called" << std::endl;
} 

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& copy) :  AForm(copy), target(copy.target)
{
    std::cout << "RobotomyRequestForm is copied" << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& rhs)
{
    if(this != &rhs)
    {
        AForm::operator=(rhs);
        target = rhs.target;
    }
    std::cout << "RobotomyRequestForm is assigned" << std::endl; 
    return *this;

}

RobotomyRequestForm::~RobotomyRequestForm() 
{
    std::cout << "RobotomyRequestForm destructor is called" << std::endl;
}

void RobotomyRequestForm::execute(const Bureaucrat& executor) const
{
    if (!getIsSigned())
        throw NotSignedException();

    if (executor.getGrade() > grade_e)
        throw GradeTooLowException();

    std::cout << "* drilling noises *" << std::endl;

    if (std::rand() % 2)
        std::cout << target << " has been robotomized successfully" << std::endl;
    else
        std::cout << "Robotomy failed" << std::endl;
}