#include "Form.hpp"

Form::Form() : name_f("Default"), grade_s(100), grade_e(100)
{
    std::cout << "[Form] " << name_f << " constructor called" << std::endl;
}

Form::Form(const std::string& name_f, const int gradeToSign, const int gradeToExecute) : name_f(name_f), grade_s(gradeToSign), grade_e(gradeToExecute)
{
    this->isSigned = false;
    if(gradeToSign < 1 || gradeToExecute < 1)
        throw GradeTooHighException();
    if(gradeToSign > 150 || gradeToExecute > 150)
        throw GradeTooLowException();
    
    std::cout << "[Form]" << name_f << " with gradeToSign: " << gradeToSign << ", gradeToExecute " << gradeToExecute << " has been created" << std::endl;
}

Form::Form(const Form& copy) : name_f(copy.name_f), grade_s(copy.grade_s), grade_e(copy.grade_e)
{
    *this = copy;
    std::cout << "[Form] copy of form " << copy.name_f  << " is created" << std::endl;
}

Form& Form::operator=(const Form& rhs)
{
    if(this != &rhs)
    {
        this->isSigned = rhs.isSigned;
    }
    std::cout << "[Form] assigned of form " << name_f << " is created" << std::endl;
    return *this;
}

Form::~Form()
{
    std::cout << "[Form] " << name_f << " is destroyed" << std::endl;
}

const std::string Form::getName() const
{
    return name_f;
}

int Form::getSignGrade() const
{
    return grade_s;
}

int Form::getExecuteGrade() const
{
    return grade_e;
}

bool Form::getIsSigned() const
{
    return isSigned;
}

const char *Form::GradeTooHighException::what() const throw()
{
    return ("Exception: Grade is too high");
}

const char *Form::GradeTooLowException::what() const throw()
{
    return ("Exception: Grade is too low");
}

void Form::beSigned(const Bureaucrat& b)
{
    if(b.getGrade() <= grade_s)
        isSigned = true;
    else
        throw GradeTooLowException();
}
std::ostream& operator<<(std::ostream& os, const Form& obj)
{
    os << obj.getName() << ", [Form] sign grade: " << obj.getSignGrade() 
    << ", [Form] execute grade: " << obj.getExecuteGrade() << std::endl;

    return os;
}