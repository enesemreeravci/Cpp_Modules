#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>

class Form;

class Bureaucrat
{
    private:
        std::string name;
        int grade;
    
    public:
        Bureaucrat();
        Bureaucrat(const std::string& name, int grade);
        Bureaucrat(const Bureaucrat& copy);
        Bureaucrat& operator=(const Bureaucrat& rhs);
        ~Bureaucrat();

        std::string getName() const;
        int getGrade() const;

        void inc(); // increase grade
        void dec(); // decrease grade
        void signForm(Form &f);
        
        class GradeTooHighException : public std::exception
        {
            public:
                const char *what() const throw();
        };
    
        class GradeTooLowException : public std::exception
        {
            public:
                const char *what() const throw();
        };
        void printBureaucrat() const;
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& obj);

#endif