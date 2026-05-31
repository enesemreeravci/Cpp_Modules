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

Character::~Character()
{
    for (int i = 0; i < 4; i++)
        delete inventory[i];
    std::cout << "[Character] destructor called" << std::endl;
}
void Character::equip(AMateria* m)
{
    if (!m)
        return;

    for (int i = 0; i < 4; i++)
    {
        if (!inventory[i])
        {
            inventory[i] = m;
            return;
        }
    }
    delete m;
}
const std::string& Character::getName() const
{
    return name;
}

void Character::unequip(int idx)
{
    if( idx < 0 || idx >= 4) 
        return;
    
    inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter& target)
{
 if (idx >= 0 && idx < 4 && inventory[idx])
        inventory[idx]->use(target);
}

AMateria* Character::getMateria(int idx) const
{
    if (idx < 0 || idx >= 4)
        return NULL;
    return inventory[idx];
}