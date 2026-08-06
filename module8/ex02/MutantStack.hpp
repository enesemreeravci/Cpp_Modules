#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <algorithm>
#include <stack>

template <class T, class Container = std::deque<T> >
class MutantStack : public std::stack<T, Container>
{
    private:
        typedef std::stack<T, Container> BaseStack;
    public:
        MutantStack() : BaseStack() {}
        MutantStack(const MutantStack& copy) : BaseStack(copy) {}
        MutantStack& operator=(const MutantStack& rhs)
        {
            if(this != &rhs)
            {
                BaseStack::operator=(rhs);
            }
            return *this;
        }
        ~MutantStack() {}

        typedef typename Container::iterator iterator;
        typedef typename Container::const_iterator const_iterator;

        iterator begin() {
            return this->c.begin();
        }
        iterator end()
        {
            return this->c.end();
        }
        const_iterator begin() const
        {
            return this->c.begin();
        }
        const_iterator end() const
        {
            return this->c.end();
        }
};

#endif