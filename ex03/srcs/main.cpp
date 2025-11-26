#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"

void crash_test()
{
    IMateriaSource* alt = new MateriaSource();
    AMateria* ice = new Ice();

    alt->learnMateria(ice);
    alt->learnMateria(ice);
    alt->learnMateria(NULL);

    delete alt;
}

int main(void)
{
    IMateriaSource* src = new MateriaSource();
    ICharacter* me = new Character("Faker");
    ICharacter* bob = new Character("bob");
    AMateria* ice = new Ice();
    AMateria* tmp;
    AMateria* tmp1;
    AMateria* tmp2;

    std::cout << "Player name : " << me->getName() << std::endl;
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

    std::cout << "___________CRASH TESTS SECTION___________" << std::endl;
    crash_test();
    delete bob;
    delete me;
    delete src;
    return 0;
}
