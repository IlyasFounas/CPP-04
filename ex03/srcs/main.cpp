#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"

void crash_test(ICharacter *me, ICharacter &bob, AMateria *tmp1)
{
    std::cout << std::endl << "___________CRASH TESTS SECTION___________" << std::endl;
    {
        IMateriaSource* alt = new MateriaSource();
        AMateria* ice = new Ice();
    
        std::cout << std::endl << "_____Give the same pointer twice_____" << std::endl;
        alt->learnMateria(ice);
        alt->learnMateria(ice);
        std::cout << std::endl << "_____Give a NULL pointer_____" << std::endl;
        alt->learnMateria(NULL);
    
        delete alt;
    }
    {
        if (!me || !tmp1)
            return ;
        std::cout << std::endl << "______Try to equipe the same materia twice______" << std::endl;
        me->equip(tmp1);
        me->equip(tmp1);

        std::cout << std::endl << "______Try to use with a bad index______" << std::endl;
        me->use(0, bob);
        me->use(2, bob);

        std::cout << std::endl << "______Try to unequipe with a bad index______" << std::endl;
        me->unequip(-1245174);
        me->unequip(2);
    }
}

int main(void)
{
    IMateriaSource* src = new MateriaSource();
    ICharacter* me = new Character("Faker");
    ICharacter* bob = new Character("bob");
    AMateria* ice = new Ice();
    AMateria* tmp = NULL;
    AMateria* tmp1 = NULL;
    AMateria* tmp2 = NULL;

    std::cout << "__________INIT__________" << std::endl << std::endl;
    std::cout << "The player name : " << me->getName() << std::endl;
    std::cout << "The player name : " << bob->getName() << std::endl;
    std::cout << std::endl;
    src->learnMateria(ice);
    src->learnMateria(new Cure());
    src->learnMateria(new Cure());
    std::cout << std::endl;

    std::cout << std::endl << "__________SOME TESTS__________" << std::endl;
    tmp = src->createMateria("ice");
    tmp1 = src->createMateria("cure");
    tmp2 = src->createMateria("cure");
    
    me->equip(tmp);
    me->equip(tmp1);
    me->equip(tmp2);
    
    me->use(0, *bob);
    me->use(1, *bob);

    me->unequip(0);
    me->unequip(1);
    me->unequip(2);

    crash_test(me, *bob, tmp1);
    delete tmp;
    delete tmp2;
    delete bob;
    delete me;
    delete src;
    return 0;
}
