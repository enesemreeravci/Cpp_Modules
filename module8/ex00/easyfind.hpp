#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <algorithm>
#include <exception>

class OccurrenceNotFound : public std::exception
{
    virtual const char* what() const throw()
    {
        return "Exception: Occurrence not found";
    }
};

template <typename T>
typename T::iterator easyfind(T& container, int target)
{

    for(typename T::iterator it = container.begin(); it != container.end(); it++)
    {
        if(*it == target)
            return it;    
    }
    throw OccurrenceNotFound();
}

    // typename T::iterator result;

    // result = std::find(container.begin(), container.end(), target);

    // if(result == container.end())
    //     throw OccurrenceNotFound();
    // return result;

#endif