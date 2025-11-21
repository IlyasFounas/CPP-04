#include "Ice.hpp"

Ice::Ice() : AMateria("ice")
{
    std::cout << "default Ice" << std::endl;
}

Ice::Ice(const Ice &copy)
{
    *this = copy;
    std::cout << "copy Ice" << std::endl;
}

Ice &Ice::operator=(const Ice &copy)
{
    if (this != &copy)
    {
        this->_type = copy._type;
    }
    return (*this);
}

Ice::~Ice()
{
    std::cout << "Ice destroyed" << std::endl;
}

void Ice::use(ICharacter& target)
{
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}

Ice *Ice::clone() const
{
    return (new Ice());
}
