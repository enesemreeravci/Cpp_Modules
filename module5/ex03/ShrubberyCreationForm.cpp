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
    std::cout << "ShrubberyCreationForm is assigned" << std::endl;
    return *this;
}

void ShrubberyCreationForm::execute(const Bureaucrat& executor) const
{
    if (!getIsSigned())
        throw NotSignedException();

    if (executor.getGrade() > grade_e)
        throw GradeTooLowException();

    std::ofstream file((target + "_shrubbery").c_str());

    if (!file)
        throw std::runtime_error("Couldn't open file.");

    file << "  *\n";
    file << " ***\n";
    file << "*****\n";
    file << "  |\n";

    std::cout << executor.getName()
              << " executed the ShrubberyCreationForm."
              << std::endl;
}