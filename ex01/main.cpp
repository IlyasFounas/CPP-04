#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

#define NB_ANIMALS 2

void printTests(Animal **objs)
{
    for (int i = 0; i < NB_ANIMALS; i++)
    {
        std::cout << objs[i]->getType() << " " << std::endl;
        objs[i]->makeSound();
    }
}

int main(void)
{
    Animal* objs[NB_ANIMALS + 1];
    Cat *c1 = new Cat();
    Dog *d1 = new Dog();
    for (int i = 0; i < NB_ANIMALS; i++)
    {
        if (i > NB_ANIMALS / 2)
            objs[i] = new Cat();
        else
            objs[i] = new Dog();
    }


    printTests(objs);
    c1->getBrain()->add("Im hungry");
    d1->getBrain()->add("Im hungry woof");

    std::cout << "cat idea : " << c1->getBrain()->get(0) << std::endl;
    std::cout << "dog idea : " << d1->getBrain()->get(0) << std::endl;
    for (int j = 0; j < NB_ANIMALS; j++)
        delete objs[j];
    delete c1;
    delete d1;
    return (0);
}
