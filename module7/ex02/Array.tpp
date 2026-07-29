#include <iostream>
#include "Array.hpp"

template <typename T>
Array<T>::Array() : arr(0), size(0)
{
    std::cout << "[Array] default constructor called" << std::endl;
}

template <typename T>
Array<T>::Array(unsigned int n) : arr(new T [n]), size(n)
{
    std::cout << "[Array] parametrized constructor called" << std::endl;
} 

template <typename T>
Array<T>::Array(const Array& copy) : arr(0), size(copy.size)
{
    if(sizee > 0)
    {
        arr = new T[size];
        for(int i = 0; i < size; i++)
           arr[i] = copy.arr[i];
    }
    std::cout << "Copy constructor called" << std::endl;
}

template <typename T>
Array<T>& Array<T>::operator=(const Array& rhs)
{
    if(this != &other)
    {
        delete[] arr;

        size = other.size;
        if(size > 0)
            new T[size];
        for(int i = 0; i < size; i++)
            arr[i] = rhs.arr[i];
    }
    std::cout << "[Array] copy assignment operator called" << std::endl;
    return *this;
}

template <typename T>
Array<T>::~Array()
{
    delete[] arr;
}
