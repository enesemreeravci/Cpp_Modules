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
        std::cout << "Enter the last name: ";
        std::getline(std::cin, last_Name);
        if(!last_Name.empty())
            break;
        else
        {
            std::cout << "Last name cannot be empty!" << std::endl;
        }
    }   

    while(true)
    {
        std::cout << "Enter the nick name: ";
        std::getline(std::cin, nick_Name);
        if(!nick_Name.empty())
            break;
        else
        {
            std::cout << "Nick name cannot be empty!" << std::endl;
        }
    }
    
    while (true)
    {
        std::cout << "Enter the phone number: ";
        std::getline(std::cin, phone_number);
        if(!phone_number.empty())
            break;
        else
        {
            std::cout << "Phone number cannot be empty!" << std::endl;
        }
    }

    while(true)
    {
        std::cout << "Enter the darkest secret: ";
        std::getline(std::cin, darkest_Secret);
        if(!darkest_Secret.empty())
            break;
        else
        {
            std::cout << "Darkest secret cannot be empty!" << std::endl;
        }
    }    
}

std::string Contact::getFirstName()
{
    return first_Name;
}

std::string Contact::getLastName()
{
    return last_Name;
}

std::string Contact::getNickName()
{
    return nick_Name;
}
std::string Contact::getPhoneNumber()
{
    return phone_number;
}
std::string Contact::getDarkestSecret()
{
    return darkest_Secret;
}

