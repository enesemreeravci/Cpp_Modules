#include <iostream>
#include "PhoneBook.hpp"

int main()
{
    PhoneBook pb_obj;
    std::string command;

    while(true)
    {
        if(!std::getline(std::cin, command))
        {
            std::cout << "Failed!" << std::endl; 
        }
        else
        {
            if(command == "ADD")
            {
                pb_obj.AddContact();
            }
            if(command == "SEARCH")
            {
                pb_obj.Search();
            }
            if(command == "EXIT")
            {
               break;
            }
        }
        if(command != "ADD" || command != "SEARCH" || command != "EXIT")
        {
            std::cout << "Unknown Command" << std::endl;

        }
    }
}
