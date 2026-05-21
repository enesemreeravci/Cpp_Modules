#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{   
    private:
        Brain* brain;

    public:
        Dog();
        Dog(const std::string& type);
        Dog(const Dog& rhs);
        Dog& operator=(const Dog& rhs);
        virtual ~Dog();

        void makeSound() const;
        void setIdeas(int index, const std::string& idea);
        std::string getIdeas(int index) const;
};

#endif