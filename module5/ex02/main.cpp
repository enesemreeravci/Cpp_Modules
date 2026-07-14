#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

#include <cstdlib>
#include <ctime>
#include <iostream>

int main()
{
    std::srand(std::time(NULL));

    Bureaucrat boss("Boss", 1);
    Bureaucrat worker("Worker", 50);
    Bureaucrat low("Low", 140);

    ShrubberyCreationForm shrub("garden");
    RobotomyRequestForm robot("Bender");
    PresidentialPardonForm pardon("Arthur Dent");

    std::cout << "\n===== SIGNING =====" << std::endl;
    boss.signForm(shrub);
    boss.signForm(robot);
    boss.signForm(pardon);

    std::cout << "\n===== SHRUBBERY =====" << std::endl;
    boss.executeForm(shrub);

    std::cout << "\n===== ROBOTOMY =====" << std::endl;
    for (int i = 0; i < 5; i++)
        boss.executeForm(robot);

    std::cout << "\n===== PRESIDENTIAL =====" << std::endl;
    boss.executeForm(pardon);

    std::cout << "\n===== EXECUTE UNSIGNED FORM =====" << std::endl;
    RobotomyRequestForm robot2("Marvin");
    boss.executeForm(robot2);

    std::cout << "\n===== GRADE TOO LOW =====" << std::endl;
    worker.executeForm(robot);     // exec grade is 45

    std::cout << "\n===== SHRUBBERY LOW GRADE =====" << std::endl;
    low.executeForm(shrub);        // exec grade is 137

    return 0;
}