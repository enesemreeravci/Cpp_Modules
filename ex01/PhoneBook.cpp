#include <iostream>
#include <cstdlib>
#include <iomanip>
#include "PhoneBook.hpp"

void PhoneBook::AddContact()
{
    Contact temp;

    temp.fillContact();
    if(count < 8)
    {
        contactsArray[count] = temp;
        count++;
    }
    else
    {
        contactsArray[oldestIndex] = temp;
        if(oldestIndex >= 0 && oldestIndex <= 6)
        {
            oldestIndex +=1 ;
        } 
        else if (oldestIndex == 7)
        {
            oldestIndex = 0;
        }
        
    }
}
std::string PhoneBook::FormatField(const std::string &str)
{
    
    std::string tempStr;
    
    if(str.length() <= 10)
    {
        return str;
    }
    else
    {
        tempStr = str.substr(0, 9) + '.';
        return tempStr;
    }
}

void PhoneBook::Search()
{
    if(count == 0)
    {
        std::cout << "PhoneBook is empty" << std::endl;
    }
    else
    {
        //setw is a formatting manipulator , it forces the total with to be 10
        std::cout << std::setw(10) << "Index" << "|" <<
        std::setw(10) << "First Name" << "|" << 
        std::setw(10) << "Last Name" << "|" <<
        std::setw(10) << "Nick Name" << "|" << std::endl;
        int i = 0;
        while(i < count)
        {
            std::cout << std::setw(10) << i << "|" << std::setw(10) << 
            FormatField(contactsArray[i].getFirstName()) <<  "|" << std::setw(10) <<
            FormatField(contactsArray[i].getLastName()) << "|" << std::setw(10) <<
            FormatField(contactsArray[i].getNickName()) << "|" << std::endl;
            i++;
        }
        std::string input;
        std::cout << "Enter index: ";
        if(!std::getline(std::cin, input));
            return; 
        if(input.empty())
        {
            std::cout << "Invalid" << std::endl;
            return;
        }
        int index = std::atoi(input.c_str());
        if(index < 0 || index >= count)
        {
            std::cout << "Invalid index" << std::endl;
            return;
        }
        else
        {
            Contact &c = contactsArray[index];
            std::cout << "First Name: " << c.getFirstName() << std::endl;
            std::cout << "Last Name: " << c.getLastName() << std::endl;
            std::cout << "Nick Name: " << c.getNickName() << std::endl;
            std::cout << "Phone Number: " << c.getPhoneNumber() << std::endl;
            std::cout << "Darkest Secret: " << c.getDarkestSecret() << std::endl;
        }
    }
}

