#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
    for (int i = 0; i < 4; i++)
        this->_tank[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource &copy)
{
    for (int i = 0; i < 4; i++)
    {
        if (copy._tank[i])
            this->_tank[i] = copy._tank[i]->clone();
        else
            this->_tank[i] = NULL;
    }
    *this = copy;
}

MateriaSource &MateriaSource::operator=(const MateriaSource &copy)
{
    if (this != &copy)
    {
        for (int i = 0; i < 4; i++)
        {
            if (this->_tank[i])
            {
                delete this->_tank[i];
                this->_tank[i] = NULL;
            }
            if (copy._tank[i])
                this->_tank[i] = copy._tank[i]->clone();
        }
    }
    return (*this);
}

MateriaSource::~MateriaSource()
{
    for (int i = 0; i < 4; i++)
        if (this->_tank[i])
            delete this->_tank[i];
}

void MateriaSource::learnMateria(AMateria *m)
{
    int i = 0;

    while (i < 4)
    {
        if (!this->_tank[i])
        {
            this->_tank[i] = m;
            std::cout << m->getType() << " successfully learned" << std::endl;
            return ;
        }
        i++;
    }
    std::cout << "The tank is full" << std::endl;
}

AMateria* MateriaSource::createMateria(std::string const &type)
{
    int i = 0;

    while (i < 4)
    {
        if (this->_tank[i] && this->_tank[i]->getType() == type)
            return (this->_tank[i]->clone());
        i++;
    }
    return (NULL);
}