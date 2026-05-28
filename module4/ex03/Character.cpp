#include "Character.hpp"

Character::Character(void) : name("")
{
    for (int i =0; i<4; i++)
    {
        inventory[i] = NULL;
    }
    std::cout << "[Character] default constructor called" << std::endl;
}

Character::Character(const std::string& name) : name(name)
{
    for (int i =0; i < 4; i++)
    {
        inventory[i] = NULL;
    }
    std::cout << "[Character] " << name << " constructor called" << std::endl;
}

Character::Character(const Character& rhs)
{
    for (int i = 0; i<4 ;i++)
    {
        if(rhs.inventory[i])
            inventory[i] = rhs.inventory[i]->clone();
        else
            inventory[i] = NULL;
    }
    std::cout << "[Character] copy constructor called" << std::endl;
}

Character& Character::operator=(const Character& rhs)
{
    if(this != &rhs)
    {
        for (int i =0; i<4; i++)
        {
            delete inventory[i];

            if(rhs.inventory[i])
                inventory[i] = rhs.inventory[i]->clone();
            else
                inventory[i] = NULL;
        }
    }
    std::cout << "[Character] assignment operator called" << std::endl;
    return *this;
}

void Character::equip(AMateria *m)
{
    if (!m )
        return;
    
    for(int i =0; i<4; i++)
    {
        if(!inventory[i])
        {
            inventory[i] = m;
            return;
        }
    }
}

void Character::unequip(int idx)
{
    if( idx < 0 || idx > 4) 
        return;
    
    inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter& target)
{
    if(idx < 0 || idx > 4)
        return;
    
    if(inventory[idx])
        inventory[idx]->use(target);
}