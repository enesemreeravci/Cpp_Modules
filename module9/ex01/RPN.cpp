#include "RPN.hpp"

RPN::RPN(void) {}

RPN::RPN(const RPN& copy)
{
    *this = copy;
}

RPN& RPN::operator=(const RPN& rhs)
{
    if(this != &rhs)    
    {
        this->numbers = rhs.numbers;
    }
    return *this;
}

RPN::~RPN() {}

bool RPN::ProcessExpression(const std::string& expression)
{

}