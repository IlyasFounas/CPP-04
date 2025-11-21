#include "Cure.hpp"

Cure::Cure() : AMateria("cure")
{
    std::cout << "default Cure" << std::endl;
}

Cure::Cure(const Cure &copy)
{
    *this = copy;
    std::cout << "copy Cure" << std::endl;
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
    std::cout << "Cure destroyed" << std::endl;
}

void Cure::use(ICharacter& target)
{
    std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl; 
}


Cure *Cure::clone() const
{
    return (new Cure());
} 