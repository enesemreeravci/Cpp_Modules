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

    // The 6 comparison operators: >, <, >=, <=, ==, and !=

    bool operator>(const Fixed& other) const;
    bool operator<(const Fixed& other) const;
    bool operator>=(const Fixed& other) const;
    bool operator<=(const Fixed& other) const;
    bool operator==(const Fixed& other) const;
    bool operator!=(const Fixed& other) const;
    
    // The 4 arithmetic operators: +, -, *, and /

    Fixed operator+(const Fixed& other) const;
    Fixed operator-(const Fixed& other) const;
    Fixed operator*(const Fixed& other) const;
    Fixed operator/(const Fixed& other) const;
    
    Fixed operator++(int); // ++x prefix: increment value first and then use
    Fixed operator--(int); // --x
    Fixed& operator++(void); // x++; postfix: use value first then increment
    Fixed& operator--(void); // x--;


    // The 4 public overloaded member functions

    static Fixed& min(Fixed& a, Fixed& b);
    static Fixed& max(Fixed& a, Fixed& b);
    static const Fixed& min(const Fixed& a, const Fixed& b);
    static const Fixed& max(const Fixed& a, const Fixed& b);

};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed_num);

#endif 