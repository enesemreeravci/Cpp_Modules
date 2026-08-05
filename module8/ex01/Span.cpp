#include "Span.hpp"

Span::Span(void)
{
    std::cout << "[Span] default constructor called" << std::endl;
}

Span::Span(unsigned int N) : maxSize(N)
{
    std::cout << "[Span] parametrized constructor called" << std::endl;
}

Span::Span(const Span& copy)
{
    *this = copy;
    std::cout << "[Span] copy constructor called" << std::endl;
}

Span::~Span()
{
    std::cout << "[Span] deconstructor called" << std::endl;
}
Span& Span::operator=(const Span& rhs)
{
    if(this != &rhs)
    {
        this->maxSize = rhs.maxSize;
        this->numbers = rhs.numbers;
    }
    std::cout << "[Span] copy assignemnt operator called" << std::endl;
    return *this;
}

int& Span::operator[](unsigned int index)
{
    if(index > maxSize)
        throw IndexExceedExceptions();
    return numbers[index];
}

const char*Span::SpanFullException::what() const throw()
{
    return "Container is already FULL";
}

const char*Span::NotEnoughNumberException::what() const throw()
{
    return "Container does not have enough numbers";
}
const char*Span::IndexExceedExceptions::what() const throw()
{
    return "Index exceeded the size";
}

void Span::addNumber(int number)
{
    if(numbers.size() >= maxSize)
    {
        throw SpanFullException();
    }
    numbers.push_back(number);
}

unsigned int Span::longestSpan()
{

    if(numbers.size() < 2)
        throw NotEnoughNumberException();
    std::vector<int>::iterator minValue;
    std::vector<int>::iterator maxValue;
    minValue = std::min_element(numbers.begin(), numbers.end());
    maxValue = std::max_element(numbers.begin(), numbers.end());    

    //std::cout << "min: " << *minValue << std::endl;
    //std::cout << "max: " << *maxValue << std::endl;

    return (*maxValue -  *minValue);
}