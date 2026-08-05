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


#endif

/*
typename T::iterator result;

result = std::find(container.begin(), container.end(), target);

if(result == container.end())
    throw OccurrenceNotFound();
return result;

An iterator is NOT a pointer, but it behaves much like one.

Think of it as a "smart pointer" that knows how to move through a container.

Operations:
*it     -> access the element (like dereferencing a pointer)
++it    -> move to the next element
--it    -> move to the previous element (if supported)
it == other_it -> compare positions

We NEVER access the iterator itself.
We access the element it points to:

iterator ---> element

*it

The actual implementation depends on the container.
For std::vector it is often implemented similarly to a pointer,
while for std::list it is a more complex object.
Therefore, always treat an iterator as an iterator, not as a raw pointer.
*/