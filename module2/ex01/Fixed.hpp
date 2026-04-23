#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
private:
    int numberFixedPoint;
    static const int numberOfFractionalBits;

    public:
    Fixed(); // default const
    Fixed(const int value_int);
    Fixed(const float value_float);
    Fixed(const Fixed& other); // copy const
    Fixed& operator=(const Fixed& other); // copy assignment operator
    ~Fixed(); // deconstructor

    int getRawBits(void) const;
    void setRawBits(int const raw);
    float toFloat( void ) const;
    int toInt( void ) const;
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed_num);

#endif 