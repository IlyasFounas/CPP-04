#include "AMateria.hpp"

AMateria::AMateria(const std::string &type) : _type(type)
{
    std::cout << "default AMateria" << std::endl;
}

AMateria::AMateria(const AMateria &copy)
{
    *this = copy;
    std::cout << "copy AMateria" << std::endl;
}

AMateria &AMateria::operator=(const AMateria &copy)
{
    if (this != &copy)
    {
        this->_type = copy._type;
    }
    return (*this);
}

AMateria::~AMateria()
{
    std::cout << "AMateria destroyed" << std::endl;
}

std::string const &AMateria::getType() const
{
    return (this->_type);
}

void AMateria::use(ICharacter& target)
{
    std::cout << target.getName() << " target locked, default attack used" << std::endl; 
}
