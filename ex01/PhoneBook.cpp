#include <iostream>
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
    if(s)
}

void PhoneBook::Search()
{
    if(count == 0)
    {
        std::cout << "PhoneBook is empty" << std::endl;
    }
    else
    {
        int i = 0;
        while(i < count)
        {
            std::cout << i << std::endl;
            std::cout << contactsArray[i].getFirstName();
            i++;

        }
    }
}

