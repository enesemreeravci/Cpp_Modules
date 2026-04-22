#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed
{
private:
    int numberFixedPoint;
    static const int numberOfFractionalBits;

    public:
    Fixed(); // default const
    Fixed(const Fixed& other); // copy const
    Fixed& operator=(const Fixed& other); // copy assignment operator
    ~Fixed(); // deconstructor

    int getRawBits(void) const;
    void setRawBits(int const raw);

};


#endif 