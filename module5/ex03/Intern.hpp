#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"

class Intern
{
    private:
        // formCreater is a pointer to a member function of Intern class
        // that receives const string& and return AForm*
        typedef AForm* (Intern::*FormCreater)(const std::string&); 
    
        AForm* createShrubbery(const std::string& target);
        AForm* createRobotomy(const std::string& target);
        AForm* createPresidential(const std::string& target);

    public:
        Intern();
        Intern(const Intern& copy);
        Intern& operator=(const Intern& rhs);
        ~Intern();

        AForm* makeForm(const std::string& formName, const std::string& formTarget);
};

#endif