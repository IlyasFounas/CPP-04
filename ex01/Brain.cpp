#include "Brain.hpp"

Brain::Brain()
{
    index = 0;
    std::cout << "Brain created" << std::endl;
}

Brain::Brain(const Brain &copy)
{
    *this = copy;
    std::cout << "copy constructor called on brain" << std::endl;
}

Brain::~Brain()
{
    std::cout << "brain destroyed" << std::endl;
}

Brain &Brain::operator=(const Brain &copy)
{
    if (this != &copy)
        for (int i = 0; i < 100; i++)
            this->ideas[i] = copy.ideas[i];
    return *this;
}

void Brain::add(const std::string idea)
{
    if (this->index == 100)
        return ;
    this->ideas[this->index] = idea;
    this->index++;
}

std::string Brain::get(int nbIndex)
{
    if (nbIndex < 0 || nbIndex >= 100)
    {
        std::cout << "Wrong Index" << std::endl;
        return (NULL);
    }
    return (this->ideas[nbIndex]);
}