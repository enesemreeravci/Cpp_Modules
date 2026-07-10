#include "Bureaucrat.hpp"
#include "AForm.hpp"
Bureaucrat::Bureaucrat() : name("default")
{
    this->grade = 150;
    std::cout << "default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string& name, int grade) : name(name), grade(grade)
{
    if(grade > 150)
        throw GradeTooHighException();
    else if (grade < 1) 
        throw GradeTooLowException();
    std::cout << "Parametrized constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& copy)
{
    *this = copy;
    std::cout << "Copy constructor called" << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
    if(this != &other)
    {
        this->grade = other.grade;
    }
    std::cout << "Copy assignemnt operator called" << std::endl;
    return *this;
}

std::string Bureaucrat::getName() const
{
    return name;
}

int Bureaucrat::getGrade() const
{
    return grade;
}

void Bureaucrat::inc()
{
    if (grade == 1)
        throw GradeTooHighException();
    grade--;
}

void Bureaucrat::dec()
{
    if (grade == 150)
        throw GradeTooLowException();
    grade++;
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
    return ("Exception: Grade is too high");
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
    return ("Exception: Grade is too low");
}
void Bureaucrat::printBureaucrat() const
{
    std::cout << "Bureaucrat's name: " << getName() << std::endl;
    std::cout << "Bureaucrat's grade: " << getGrade() << std::endl;
}

// for ex01
void Bureaucrat::signForm(AForm& f)
{
    try
    {
        f.beSigned(*this);
        std::cout << getName() << " signed " << f.getName() << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << getName() << " couldn't sign "
                  << f.getName()
                  << " because "
                  << e.what()
                  << std::endl;
    }
}

Bureaucrat::~Bureaucrat()
{
    std::cout << "Destructor called" << std::endl;
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& obj)
{
    os << obj.getName() << ", bureacrat grade: " << obj.getGrade() << std::endl;
    return os;
}