#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <algorithm>
#include <vector>
#include <exception>

class Span
{
    private:
        // the subject specifiaclly says the class stores integers.
        std::vector<int> numbers; 
        unsigned int maxSize; // max number for a span object can take
        Span(void); // will not create an object without number
    public:
        Span(unsigned int N);
        Span(const Span& copy);
        Span& operator=(const Span& rhs);
        ~Span();
        int& operator[](unsigned int index);

        void addNumber(int number);
        unsigned int shortestSpan() const;
        unsigned int longestSpan() const;
        unsigned int getSize() const;
        
        class SpanFullException : public std::exception
        {
            virtual const char* what() const throw();
        };
        class NotEnoughNumberException : public std::exception
        {
            virtual const char* what() const throw();
        };  
        // for [] operator
        class IndexExceedExceptions : public std::exception
        {
            virtual const char* what() const throw();
        };
        
        template<typename iterator>
        void addRange(iterator first , iterator last)
        {
            unsigned int count = std::distance(first, last);

            if(numbers.size() + count > getSize())
                throw SpanFullException();
            numbers.insert(numbers.end(), first, last);
        }
        
};

#endif