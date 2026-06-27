#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
    private:    
        const std::string name_f;
        bool isSigned;
        const int grade_s;
        const int grade_e;
    
    public:
        Form();
        Form(const std::string& name_f, const int gradeToSign, const int gradeToExecute);
        Form(const Form& copy);
        Form& operator=(const Form& rhs);
        ~Form();

        void beSigned(const Bureaucrat& b);

        const std::string getName() const;
        int getSignGrade() const;
        int getExecuteGrade() const;
        bool getIsSigned() const;

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
};

std::ostream& operator<<(std::ostream& os, const Form& obj);

#endif