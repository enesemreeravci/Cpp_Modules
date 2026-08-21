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

static bool IsOperator(const std::string& op) 
{
    if(op == "+" || op == "-" || op == "*" || op == "/")
        return true;
    return false;
}

static bool IsSingleDigit(const std::string& token)
{
    if(token.length() == 1 && isdigit(token[0]))
        return true;
    return false;

}

bool RPN::ApplyOperations(const std::string& op)
{
    if(numbers.size() >= 2)  
    {
        int right = numbers.top();
        numbers.pop();
        int left = numbers.top();
        numbers.pop();
        int result = 0;
        
        if(op == "+")
        {
            result = left + right;
        }
        else if(op == "-")
        {
            result = left - right;
        }
        else if(op == "*")
        {
            result = left * right;
        }
        else if(op == "/")
        {
            if(right == 0)
                return false;
            result =  left / right;
        }
        numbers.push(result);
        return true;
    }
    return false; 
}

bool RPN::ProcessExpression(const std::string& expression)
{   
    std::istringstream ss(expression);
    std::string token;

    while(ss >> token)
    {
        // std::cout << token << std::endl;
        if(IsSingleDigit(token))
        {
            int value = token[0] - '0';
            numbers.push(value);
        }
        else if(IsOperator(token))
        {
            if(ApplyOperations(token) == false)
            {
                std::cerr << "Error" << std::endl;
                return false; 
            }  
        }
        else
        {
            std::cerr << "Error" << std::endl;
            return false; 
        }
        
    }
    if(numbers.size() != 1)
        return false;
    int res = numbers.top();
    std::cout << res << std::endl;
    return true;
}