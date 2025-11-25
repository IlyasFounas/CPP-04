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
    AMateria* tmp1;
    AMateria* tmp2;

    AMateria* ice = new Ice();
    src->learnMateria(ice);
    src->learnMateria(NULL);
    src->learnMateria(ice);
    src->learnMateria(new Cure());
    src->learnMateria(new Cure());
    std::cout << std::endl;

    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp1 = src->createMateria("cure");
    tmp2 = src->createMateria("cure");
    me->unequip(-100);
    me->equip(tmp1);
    me->equip(tmp1);
    me->equip(tmp2);

    me->use(0, *bob);
    me->use(1, *bob);

    delete bob;
    delete me;
    delete src;
    // delete tmp;
    return 0;
}
