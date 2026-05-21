#include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{
    std::cout << "[Cat] default constructor called" << std::endl;
    brain = new Brain();

}


Cat::Cat(const Cat& rhs) : Animal(rhs)
{
    std::cout << "[Cat] copy constructor called" << std::endl; 
    this->brain = new Brain(*(rhs.brain));
    // Instead of copying the pointer (shallow), we allocate a NEW brain
    // and invoke Brain's copy constructor to copy the 100 strings.
}

Cat& Cat::operator=(const Cat& rhs)
{
    if(this != &rhs)
    {
        Animal::operator=(rhs);

        delete this->brain;

        this->brain = new Brain(*(rhs.brain));
    }
    std::cout << "[Cat] copy assignment operator called "<< std::endl;
    return *this;
}

Cat::~Cat()
{
    std::cout << "[Cat] destructor called" << std::endl;
    delete brain;
}

void Cat::makeSound() const
{
    std::cout << "[Cat]: makeSound() called and sound : MEOW MEOW" << std::endl;
}

void Cat::setIdeas(int index, const std::string& idea)
{
    brain->setIdeas(index, idea);
}

std::string Cat::getIdeas(int index) const
{
    return (brain->getIdeas(index));
}