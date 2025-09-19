#include "Cat.hpp"

Cat::Cat() : Animal("cat") 
{
    this->brain = new Brain();
    std::cout << "Cat created" << std::endl;
}

Cat::Cat(const Cat &other) : Animal(other) {
    std::cout << "Cat copy constructor called" << std::endl;
    *this = other;
}


Cat &Cat::operator=(const Cat &other)
{
    if (this != &other)
        this->type = other.type;
    return (*this);
}

Cat::~Cat()
{
    delete this->brain;
    std::cout << "Cat destroyed" << std::endl;
}

void Cat::makeSound() const
{
    std::cout << "miaow miaow !" << std::endl;
}

Brain* Cat::getBrain(void) const
{
    return (this->brain);
}