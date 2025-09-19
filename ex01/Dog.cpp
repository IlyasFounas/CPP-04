#include "Dog.hpp"
#include "Brain.hpp"

Dog::Dog() : Animal("Dog")
{
    this->brain = new Brain();
    std::cout << "Dog created" << std::endl;
}

Dog::Dog(const Dog &other) : Animal(other)
{
    std::cout << "Dog copy constructor called" << std::endl;
    *this = other;
}

Dog &Dog::operator=(const Dog &other)
{
    if (this != &other)
        this->type = other.type;
    return (*this);
}

Dog::~Dog()
{
    delete this->brain;
    std::cout << "Dog destroyed" << std::endl;
}

void Dog::makeSound() const
{
    std::cout << "Woof woof !" << std::endl;
}

Brain* Dog::getBrain(void) const
{
    return (this->brain);
}
