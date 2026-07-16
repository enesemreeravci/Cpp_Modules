#include "Intern.hpp"
#include "Bureaucrat.hpp"

#include <cstdlib>
#include <ctime>

int main()
{
    std::srand(std::time(NULL));

    Intern intern;
    Bureaucrat boss("Boss", 1);

    AForm* form;

    std::cout << "\n===== Robotomy =====\n";
    form = intern.makeForm("robotomy request", "Bender");
    if (form)
    {
        boss.signForm(*form);
        boss.executeForm(*form);
        delete form;
    }

    std::cout << "\n===== Shrubbery =====\n";
    form = intern.makeForm("shrubbery creation", "garden");
    if (form)
    {
        boss.signForm(*form);
        boss.executeForm(*form);
        delete form;
    }

    std::cout << "\n===== Presidential =====\n";
    form = intern.makeForm("presidential pardon", "Arthur Dent");
    if (form)
    {
        boss.signForm(*form);
        boss.executeForm(*form);
        delete form;
    }

    std::cout << "\n===== Invalid =====\n";
    form = intern.makeForm("coffee request", "office");

    if (form)
        delete form;

    return 0;
}