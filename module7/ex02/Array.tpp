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
    if(size > 0)
    {
        arr = new T[size];
        for(unsigned int i = 0; i < size; i++)
           arr[i] = copy.arr[i];
    }
    std::cout << "Copy constructor called" << std::endl;
}

template <typename T>
Array<T>& Array<T>::operator=(const Array& rhs)
{
    if(this != &rhs)
    {
        delete[] arr;

        size = rhs.size;
        arr = NULL;
        if(size > 0)
        {
            arr = new T[size];
        }
        for(unsigned int i = 0; i < size; i++)
        {
            arr[i] = rhs.arr[i];
        }
    }
    std::cout << "[Array] copy assignment operator called" << std::endl;
    return *this;
}

template <typename T>
Array<T>::~Array()
{
    std::cout << "[Array] deconstructor called" << std::endl;
    delete[] arr;
}

template<typename T>
const char* Array<T>::SizeExceedException::what() const throw()
{
    return "Index excced the size";
}

template <typename T>
T& Array<T>::operator[](unsigned int index)
{
    if(index >= getSize())
    {
        throw Array<T>::SizeExceedException();
    }
    return arr[index];
}

template <typename T>
const T& Array<T>::operator[](unsigned int index) const
{
    if(index >= getSize())
        throw Array<T>::SizeExceedException();
    return arr[index];
}   

template <typename T>
unsigned int Array<T>::getSize() const
{
    return size;
}

