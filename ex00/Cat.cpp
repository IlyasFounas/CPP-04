#include "Cat.hpp"

Cat::Cat() : Animal("cat") 
{
    std::cout << "Cat created" << std::endl;
}

Cat::Cat(const Cat &other) : Animal(other) {
    std::cout << "Cat copy constructor called" << std::endl;
    *this = other;
}


Cat &Cat::operator=(const Cat &other)
{
    if (this != &other)
        this->_type = other._type;
    return (*this);
}

Cat::~Cat() {
    std::cout << "Cat destroyed" << std::endl;
}

void Cat::makeSound() const
{
    std::cout << "miaow miaow !" << std::endl;
}