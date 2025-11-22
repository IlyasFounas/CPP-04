#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"
#include "AMateria.hpp"

class IMateriaSource;
class AMateria;

class MateriaSource : public IMateriaSource
{
    public:
        MateriaSource();
        MateriaSource(const MateriaSource &copy);
        MateriaSource &operator=(const MateriaSource &copy);
        virtual ~MateriaSource();

        // member functions
        virtual void learnMateria(AMateria *m);
        virtual AMateria* createMateria(std::string const &type);
    
    private:
        AMateria *_tank[4];
};

#endif