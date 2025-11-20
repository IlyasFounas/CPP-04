#include "Animal.hpp"

Animal::Animal() : _type("Default Animal")
{
    std::cout << "Default Animal created" << std::endl;
}

Animal::Animal(const std::string type) : _type(type)
{
    std::cout << type << " created" << std::endl;
}

Animal::Animal(const Animal &other)
{
    std::cout << "Animal copy constructor called" << std::endl;
    *this = other;
}

Animal &Animal::operator=(const Animal &other)
{
    if (this != &other)
    {
        this->_type = other._type;
    }
    return (*this);
}

Animal::~Animal()
{
    std::cout << "Animal destroyed" << std::endl;
}


std::string Animal::getType() const
{
    return (this->_type);
}

void Animal::makeSound() const
{
    std::cout << "Default sound" << std::endl;
}
