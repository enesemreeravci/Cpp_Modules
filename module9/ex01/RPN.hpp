#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>
#include <string>
#include <sstream>

class RPN
{
    private:
        std::stack<int> numbers;
    
    public:
        RPN(void);
        RPN(const RPN& copy);
        RPN& operator=(const RPN& rhs);
        ~RPN();

        bool ProcessExpression(const std::string& expression);
        bool ApplyOperations(const std::string& op);

};
#endif