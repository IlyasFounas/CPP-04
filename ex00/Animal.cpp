#include "Animal.hpp"

Animal::Animal()
{
    std::cout << "default animal created" << std::endl;
    this->type = "Default";
}

Animal::Animal(const std::string type)
{
    std::cout << type << " created" << std::endl;
    this->type = type;
}

Animal::Animal(const Animal &other)
{
    std::cout << "copy constructor called" << std::endl;
    *this = other;
}

Animal &Animal::operator=(const Animal &other)
{
    if (this != &other)
    {
        this->type = other.type;
    }
    return (*this);
}

Animal::~Animal()
{
    std::cout << "animal destroyed" << std::endl;
}


std::string Animal::getType() const
{
    return (this->type);
}

void Animal::makeSound() const
{
    std::cout << "default sound" << std::endl;
}
