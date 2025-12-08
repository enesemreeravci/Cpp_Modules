#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include <string>

class PhoneBook
{
    private:
        Contact contactsArray[8];
        int count;
        int oldestIndex;
        std::string FormatField(const std::string &str);
    public:
        PhoneBook(/* args */);
        ~PhoneBook();
        void AddContact();
        void Search();
};


#endif