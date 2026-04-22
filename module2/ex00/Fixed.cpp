#include "Fixed.hpp"

const int Fixed::numberOfFractionalBits = 8;

Fixed::Fixed() : numberFixedPoint(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

Fixed& Fixed::operator=(const Fixed& other)
{
    std::cout << "Copy assignment operator called" << std::endl;
    // Self-assignment protection  
    if(this != &other)
    {
        setRawBits(other.getRawBits());
    }
    return *this;
    // this->numberFixedPoint = other.numberFixedPoint;
}

Fixed::~Fixed()
{
    std::cout << "Deconstructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function is called" << std::endl;
    return numberFixedPoint;
    // return this->numberFixedPoint; this is also same meaning
}

void Fixed::setRawBits(int const numberFixedPoint)
{
    this->numberFixedPoint = numberFixedPoint;
}