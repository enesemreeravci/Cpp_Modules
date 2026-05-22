#include "Brain.hpp"

Brain::Brain()
{
    std::cout << "[Brain] default constructor called" << std::endl;
}

Brain::Brain(const Brain& rhs)
{
    for(int i = 0; i < 100; i++)
    {
        this->ideas[i] = rhs.ideas[i];
    }
    std::cout << "[Brain] copy constructor called" << std::endl;
}

Brain& Brain::operator=(const Brain& rhs)
{
    if(this != &rhs)
    {
        for (int i = 0; i < 100; i++)
        {
            this->ideas[i] = rhs.ideas[i];
        }
    }
    std::cout << "[Brain] copy assignment operator called" << std::endl;
    return *this;
}

Brain::~Brain()
{
   std::cout << "[Brain] copy constructor called" << std::endl;
}

void Brain::setIdeas(int index, const std::string& idea)
{
    if(index >= 0 && index < 100)
    {
        ideas[index] = idea;
    }

}

std::string Brain::getIdeas(int index) const
{
    static const std::string empty = "";

    return (index >= 0 && index < 100) ? ideas[index] : empty;
}