#include <iostream>
#include "PhoneBook.hpp"

#define RED     "\e[1;31m"
#define GREEN   "\e[1;32m"
#define RESET   "\e[0m"

int main()
{
    PhoneBook pb_obj;
    std::string command;
    std::cout << RED << " Welcome to First OOP Experience of EEE" << RESET << std::endl;
    while (true)
    {
        std::cout << "VALID COMMANDS : "<< GREEN << "ADD" << RESET << " " << GREEN << "SEARCH" << RESET << " " << GREEN << "EXIT" << RESET << "\n";
        std::cout << RED << "> " << RESET;

        if (!std::getline(std::cin, command))
        {
            std::cout << "Input error, exiting..." << std::endl;
            break;
        }

        if (command == "ADD")
        {
            pb_obj.AddContact();
            std::cout << GREEN << "Contact added successfully\n" << RESET; 
        }
        else if (command == "SEARCH")
        {
            pb_obj.Search();
            std::cout << GREEN <<"Searched succesfully\n" << RESET;
        }
        else if (command == "EXIT")
        {
            std::cout << GREEN << "Byeeeeeeeeeeeeeeeeeeeeeee\n" << RESET; 
            break;
        }
        else
        {
            std::cout << "Unknown Command" << std::endl;
        }
    }
}