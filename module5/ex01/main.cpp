#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    std::cout << "===== Bureaucrats =====\n";
    Bureaucrat alice("Alice", 1);
    Bureaucrat bob("Bob", 75);
    Bureaucrat charlie("Charlie", 150);

    std::cout << alice << std::endl;
    std::cout << bob << std::endl;
    std::cout << charlie << std::endl;

    std::cout << "\n===== Valid Forms =====\n";
    Form topSecret("TopSecret", 10, 5);
    Form contract("Contract", 100, 50);

    std::cout << topSecret << std::endl;
    std::cout << contract << std::endl;

    std::cout << "\n===== Signing Tests =====\n";

    alice.signForm(topSecret);      // Should succeed
    bob.signForm(topSecret);        // Should fail

    std::cout << topSecret << std::endl;

    bob.signForm(contract);         // Should succeed
    charlie.signForm(contract);     // Should fail (or already signed)

    std::cout << contract << std::endl;

    std::cout << "\n===== Invalid Forms =====\n";

    try
    {
        Form bad1("Bad1", 0, 10);
    }
    catch (const std::exception& e)
    {
        std::cout << "Failed to create Bad1: " << e.what() << std::endl;
    }

    try
    {
        Form bad2("Bad2", 151, 10);
    }
    catch (const std::exception& e)
    {
        std::cout << "Failed to create Bad2: " << e.what() << std::endl;
    }

    try
    {
        Form bad3("Bad3", 10, 0);
    }
    catch (const std::exception& e)
    {
        std::cout << "Failed to create Bad3: " << e.what() << std::endl;
    }

    try
    {
        Form bad4("Bad4", 10, 151);
    }
    catch (const std::exception& e)
    {
        std::cout << "Failed to create Bad4: " << e.what() << std::endl;
    }

    return 0;
}