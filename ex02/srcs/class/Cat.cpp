#include "Cat.hpp"

Cat::Cat() : Animal("cat"), _brain(new Brain())
{
    std::cout << "Default Cat created" << std::endl;
}

Cat::Cat(const Cat &other) : Animal(other) {
    std::cout << "Cat copy constructor called" << std::endl;
    *this = other;
}

Cat &Cat::operator=(const Cat &other)
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

Cat::~Cat()
{
    std::cout << "Cat destroyed" << std::endl;
    delete this->_brain;
}

void Cat::makeSound() const
{
    std::cout << "miaow miaow !" << std::endl;
}

Brain* Cat::getBrain() const
{
    return (this->_brain);
}