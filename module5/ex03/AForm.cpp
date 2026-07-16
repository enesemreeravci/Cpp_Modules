#include "AForm.hpp"

AForm::AForm() : name_f("Default"), grade_s(100), grade_e(100)
{
    std::cout << "[Form] " << name_f << " constructor called" << std::endl;
}

AForm::AForm(const std::string& name_f, const int gradeToSign, const int gradeToExecute) : name_f(name_f), grade_s(gradeToSign), grade_e(gradeToExecute)
{
    this->isSigned = false;
    if(gradeToSign < 1 || gradeToExecute < 1)
        throw GradeTooHighException();
    if(gradeToSign > 150 || gradeToExecute > 150)
        throw GradeTooLowException();
    
    std::cout << "[AForm]" << name_f << " with gradeToSign: " << gradeToSign << ", gradeToExecute " << gradeToExecute << " has been created" << std::endl;
}

AForm::AForm(const AForm& copy) : name_f(copy.name_f), grade_s(copy.grade_s), grade_e(copy.grade_e)
{
    *this = copy;
    std::cout << "[AForm] copy of AForm " << copy.name_f  << " is created" << std::endl;
}

AForm& AForm::operator=(const AForm& rhs)
{
    if(this != &rhs)
    {
        this->isSigned = rhs.isSigned;
    }
    std::cout << "[AForm] assigned of AForm " << name_f << " is created" << std::endl;
    return *this;
}

AForm::~AForm()
{
    std::cout << "[AForm] " << name_f << " is destroyed" << std::endl;
}

const std::string AForm::getName() const
{
    return name_f;
}

int AForm::getSignGrade() const
{
    return grade_s;
}

int AForm::getExecuteGrade() const
{
    return grade_e;
}

bool AForm::getIsSigned() const
{
    return isSigned;
}

const char *AForm::GradeTooHighException::what() const throw()
{
    return ("Exception: Grade is too high");
}

const char *AForm::GradeTooLowException::what() const throw()
{
    return ("Exception: Grade is too low");
}

const char *AForm::NotSignedException::what() const throw()
{
    return ("Exception: Grade is not signed");
}

void AForm::beSigned(const Bureaucrat& b)
{
    if(b.getGrade() <= grade_s)
        isSigned = true;
    else
        throw GradeTooLowException();
}
std::ostream& operator<<(std::ostream& os, const AForm& obj)
{
    os << obj.getName() << ", [AForm] sign grade: " << obj.getSignGrade() 
    << ", [AForm] execute grade: " << obj.getExecuteGrade() << std::endl;

    return os;
}