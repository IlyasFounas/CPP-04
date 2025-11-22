#include "Character.hpp"

Character::Character() : _name("bot")
{
    for (int i = 0; i < 4; i++)
        this->_slots[i] = NULL;
}

Character::Character(const std::string &name) : _name(name)
{
    for (int i = 0; i < 4; i++)
        this->_slots[i] = NULL;
}

Character::Character(const Character &copy)
{
    for (int i = 0; i < 4; i++)
    {
        if (copy._slots[i])
            this->_slots[i] = copy._slots[i]->clone();
        else
            this->_slots[i] = NULL;
    }
    *this = copy;
}

Character &Character::operator=(const Character &copy)
{
    if (this != &copy)
    {
        for (int i = 0; i < 4; i++)
        {
            if (this->_slots[i])
            {
                delete this->_slots[i];
                this->_slots[i] = NULL;
            }
            if (copy._slots[i])
                this->_slots[i] = copy._slots[i]->clone();
        }
        this->_name = copy._name;
    }
    return (*this);
}

Character::~Character()
{
    for (int i = 0; i < 4; i++)
        if (this->_slots[i])
            delete this->_slots[i];
}

std::string const &Character::getName() const
{
    return (this->_name);
}

void Character::equip(AMateria *m)
{
    int i = 0;
    int add = 1;
    int check_index = 0;

    while (check_index < 4)
    {
        if (this->_slots[check_index] == m)
        {
            add = 0;
            break ;
        }
        check_index++;
    }
    if (add == 0)
    {
        std::cout << "Error this Materia is already equiped" << std::endl;
        return ;
    }
    while (i < 4)
    {
        if (!this->_slots[i])
        {
            this->_slots[i] = m;
            std::cout << m->getType() << " successfully equiped" << std::endl;
            return ;
        }
        i++;
    }
    std::cout << "You havn't slots left" << std::endl;
}

void Character::unequip(int idx)
{
    std::string materia_type;

    if (idx < 0 || idx >= 4)
        std::cout << "The index is invalid" << std::endl;
    else if (!this->_slots[idx])
        std::cout << "havn't any Materia at this slot" << std::endl;
    else if (this->_slots[idx])
    {
        materia_type = this->_slots[idx]->getType();
        this->_slots[idx] = NULL;
        std::cout << materia_type << " successfully unequiped" << std::endl;
    }
    return ;
}

void Character::use(int idx, ICharacter& target)
{
    if (idx < 0 || idx >= 4)
        std::cout << "The index is invalid" << std::endl;
    else if (!this->_slots[idx])
        std::cout << "havn't any Materia at this slot" << std::endl;
    else if (this->_slots[idx])
    {
        this->_slots[idx]->use(target);
    }
}
