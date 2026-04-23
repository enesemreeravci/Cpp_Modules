#include "Fixed.hpp"

const int Fixed::numberOfFractionalBits = 8;

Fixed::Fixed() : numberFixedPoint(0)
{
    std::cout << "Default constructor called" << std::endl;
}
Fixed::Fixed(const int val_int)
{
    std::cout << "Const int constructor called" << std::endl;
    numberFixedPoint = val_int << numberOfFractionalBits;
    return;
}

Fixed::Fixed(const float val_float)
{
    std::cout << "Const float constructor called" << std::endl;
    numberFixedPoint = roundf(val_float * (1 << numberOfFractionalBits));
    return; 

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
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function is called" << std::endl;
    return numberFixedPoint;
    // return this->numberFixedPoint; this is also same meaning
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed_num)
{
    os << fixed_num.toFloat();
    return os;
}

void Fixed::setRawBits(int const numberFixedPoint)
{
    this->numberFixedPoint = numberFixedPoint;
}

float Fixed::toFloat(void) const
{
    return (float(numberFixedPoint)) / (1 << numberOfFractionalBits);
}

int Fixed::toInt(void) const
{
    return (numberFixedPoint >> numberOfFractionalBits);
}