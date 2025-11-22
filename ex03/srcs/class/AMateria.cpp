#include "AMateria.hpp"

AMateria::AMateria() : _type("default")
{
}

AMateria::AMateria(const std::string &type) : _type(type)
{
}

AMateria::AMateria(const AMateria &copy)
{
    *this = copy;
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
}

std::string const &AMateria::getType() const
{
    return (this->_type);
}

void AMateria::use(ICharacter& target)
{
    std::cout << target.getName() << " target locked, default attack used" << std::endl; 
}
