#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <exception>

template <typename T>
class Array
{
    private:    
        T* arr;
        unsigned int size;
    public:
        Array();
        Array(unsigned int n);
        Array(const Array& copy);
        Array& operator=(const Array& rhs);
        ~Array();

        T& operator[](unsigned int index);
        const T& operator[](unsigned int index) const;

        class SizeExceedException : public std::exception
        {
            virtual const char *what() const throw();
        };

        unsigned int getSize() const;
    
        
};

#include "Array.tpp"

#endif