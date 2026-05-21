#include "Dog.hpp"

Dog::Dog() : Animal("Dog")
{
    std::cout << "[Dog] default consturctor called" << std::endl;
    brain = new Brain();

}

Dog::Dog(const Dog& rhs) : Animal(rhs)
{
    std::cout << "[Dog] copy constructor called" << std::endl;
    this->brain = new Brain(*(rhs.brain));
}

Dog& Dog::operator=(const Dog& rhs)
{
    if(this != &rhs)
    {
        Animal::operator=(rhs);

        delete this->brain;

        this->brain = new Brain(*(rhs.brain));
    }
    std::cout << "[Dog] copy assignment operator called" << std::endl;
    return *this;
}

Dog::~Dog()
{
    std::cout << "[Dog] destructor called" << std::endl;
    delete brain;
}

void Dog::makeSound() const
{
    std::cout << "[Dog]: makeSound() called and sound : WOOF WOOF" <<  std::endl;
}

void Dog::setIdeas(int index, const std::string& idea)
{
    brain->setIdeas(index, idea);
}

std::string Dog::getIdeas(int index) const
{
    return brain->getIdeas(index);
}