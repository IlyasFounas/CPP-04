#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main(void)
{
    {
        const Animal* meta = new Animal();
        const Animal* j = new Dog();
        const Animal* i = new Cat();
    
        std::cout << std::endl << "__________SOME TESTS__________" << std::endl;
        std::cout << j->getType() << std::endl;
        std::cout << i->getType() << std::endl << std::endl;

        i->makeSound();
        j->makeSound();
        meta->makeSound();

        std::cout << std::endl;
        delete i;
        delete j;
        delete meta;
        std::cout << "______________________________" << std::endl;
    }
    {
        std::cout << std::endl << "_______WRONGANIMAL TEST_______" << std::endl;
        const WrongAnimal wrong;
        const WrongAnimal* cat = new WrongCat();
        
        std::cout << cat->getType() << std::endl;
        wrong.makeSound();
        cat->makeSound();
    
        std::cout << std::endl;
        delete cat;
    }
    std::cout << "________________________________" << std::endl;
    return (0);
}