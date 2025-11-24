#include "Contact.hpp"
#include <iostream>

void    Contact::fillContact()
{
    // it is not the best way but i think it will work out.
    while(true)
    {
        std::cout << "Enter the first name: ";
        std::getline(std::cin, first_Name);
        if(!first_Name.empty())
            break;
        else
        {
            std::cout << "Name cannot be empty!" << std::endl;
        }
    } 

    while(true)
    {
        //same pattern for lastname nickname phonenumber and secret !
    }
    
}