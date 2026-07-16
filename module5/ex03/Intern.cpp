#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern()
{
    std::cout << "Intern constructor called" << std::endl;
}

Intern::Intern(const Intern& copy)
{
    (void)copy;
    std::cout << "Intern copy const called" << std::endl;
}

Intern& Intern::operator=(const Intern& rhs)
{
    (void)rhs;
    std::cout << "Intern assignment operator called" << std::endl;
    return *this;
} 

Intern::~Intern()
{
    std::cout << "Intern destructor called" << std::endl;
}

AForm* Intern::createPresidential(const std::string& target)
{
    return new ShrubberyCreationForm(target);
}

AForm* Intern::createRobotomy(const std::string& target)
{
    return new RobotomyRequestForm(target);
}

AForm* Intern::createShrubbery(const std::string& target)
{
    return new ShrubberyCreationForm(target);
}

AForm* Intern::makeForm(const std::string& formName, const std::string& formTarget)
{
    const std::string names[3] = {
        "shrubbery creation",
        "robotomy request",
        "presidential pardon"
    };

    // each of them is a pointer to one of the intern member functions
    FormCreater creators[3] = {
        &Intern::createShrubbery,
        &Intern::createRobotomy,
        &Intern::createPresidential
    };

    for (int i = 0; i < 3; i++)
    {
        if(formName == names[i])
        {                   // current object is accesing the appropiate function
            AForm* form = (this->*creators[i])(formTarget);
            // CALL THE CORRECT CREATER FUNCTION ON THE INTERN AND STORE THE CREATED FORM 
            std::cout << "Intern creates " << formName << std::endl;
            return form;
        }
    }
    std::cout << "Intern cannot create unknown form: " 
    << formName << std::endl;
    return NULL;
}