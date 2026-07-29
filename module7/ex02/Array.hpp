#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

template <typename T>
class Array
{
    private:    
        T* arr;
        int size;
    public:
        Array();
        Array(unsigned int n);
        Array(const Array& copy);
        Array& operator=(const Array& rhs);
        ~Array();




        
};

#endif