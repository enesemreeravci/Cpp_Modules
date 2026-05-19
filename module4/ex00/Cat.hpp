#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"

class Cat : public Animal
{
    public:
        Cat();
        Cat(const std::string& type);
        Cat(const Cat& rhs);
        Cat& operator=(const Cat& rhs);
        virtual ~Cat();

        void makeSound() const;    
};

#endif