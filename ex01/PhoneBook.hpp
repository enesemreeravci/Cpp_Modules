#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include <string>
// define classes-function etc

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

PhoneBook::PhoneBook() : count(0), oldestIndex(0)
{
}

PhoneBook::~PhoneBook()
{
}

#endif