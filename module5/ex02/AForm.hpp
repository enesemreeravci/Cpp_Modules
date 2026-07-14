#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <string>
#include <fstream>
#include <exception>
#include <stdexcept>

#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
    protected:    
        const std::string name_f;
        bool isSigned;
        const int grade_s;
        const int grade_e;
    
    public:
        AForm();
        AForm(const std::string& name_f, const int gradeToSign, const int gradeToExecute);
        AForm(const AForm& copy);
        AForm& operator=(const AForm& rhs);
        ~AForm();

        void beSigned(const Bureaucrat& b);
        virtual void execute(const Bureaucrat& executor) const = 0;

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
        
        class NotSignedException : public std::exception
        {
            public:
                const char *what() const throw();
        };
};

std::ostream& operator<<(std::ostream& os, const AForm& obj);

#endif