#include "Cure.hpp"

Cure::Cure() : AMateria("cure")
{
}

Cure::Cure(const Cure &copy)
{
    *this = copy;
}

Cure &Cure::operator=(const Cure &copy)
{
    if (this != &copy)
    {
        this->_type = copy._type;
    }
    return (*this);
}

Cure::~Cure()
{
}

void Cure::use(ICharacter& target)
{
    std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl; 
}


Cure *Cure::clone() const
{
    return (new Cure());
} 