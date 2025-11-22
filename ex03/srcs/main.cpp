#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"

int main(void)
{
    IMateriaSource* src = new MateriaSource();
    ICharacter* me = new Character("me");
    ICharacter* bob = new Character("bob");
    AMateria* tmp;
    AMateria* tmp2;

    src->learnMateria(new Ice());
    src->learnMateria(new Cure());

    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    tmp2 = src->createMateria("cure");
    me->equip(tmp);
    me->equip(tmp);
    me->equip(tmp2);

    me->use(0, *bob);
    me->use(1, *bob);

    delete bob;
    delete me;
    delete src;
    return 0;
}
