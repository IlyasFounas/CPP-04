#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main(void)
{
    std::cout << "CONSTRUCTORS : " << std::endl;
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();


    std::cout << std::endl << "SOME TESTS : " << std::endl;
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    i->makeSound();
    j->makeSound();
    meta->makeSound();


    std::cout << std::endl << "WRONGANIMAL TEST : " << std::endl;
    const WrongAnimal* wrong = new WrongCat();
    std::cout << wrong->getType() << std::endl;
    wrong->makeSound();


    std::cout << std::endl << "DESTRUCTORS : " << std::endl;
    delete i;
    delete j;
    delete meta;
    delete wrong;
    return (0);
}