#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>
// define classes-function etc

class Contact
{

    private:
    // 5 private string
    std::string first_Name;
    std::string last_Name;
    std::string nick_Name;
    std::string phone_number;
    std::string darkest_Secret;

    public:
    //Contact(); // consturctor
    void fillContact(); //ask user for input  
    std::string getFirstName();
    std::string getLastName();
    std::string getNickName();
    std::string getPhoneNumber();
    std::string getDarkestSecret();
    

    //Contact::Contact();
    
};


#endif