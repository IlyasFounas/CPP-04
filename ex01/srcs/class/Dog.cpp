#include "Dog.hpp"

Dog::Dog() : Animal("dog"), _brain(new Brain())
{
    std::cout << "Default Dog created" << std::endl;
}

Dog::Dog(const Dog &other) : Animal(other)
{
    std::cout << "Dog copy constructor called" << std::endl;
    *this = other;
}

Dog &Dog::operator=(const Dog &other)
{
    if (this != &other)
    {
        if (this->_brain)
            delete this->_brain;
        this->_type = other._type;
		this->_brain = new Brain(*other._brain);
    }
    return (*this);
}

Dog::~Dog()
{
    std::cout << "Dog destroyed" << std::endl;
    delete this->_brain;
}

void Dog::makeSound() const
{
    std::cout << "Woof woof !" << std::endl;
}

Brain* Dog::getBrain() const
{
    return (this->_brain);
}
