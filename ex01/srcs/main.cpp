#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

#define NB_ANIMALS 4

void printTests(Animal **objs)
{
    for (int i = 0; i < NB_ANIMALS; i++)
    {
        std::cout << objs[i]->getType() << " " << std::endl;
        objs[i]->makeSound();
    }
}

void toMuchThinking(Dog *dog, Cat *cat)
{
    int i = 0;
    std::string idea;
    std::string type;

    if (dog)
        type = "dog";
    else
        type = "cat";
    while (i < 100)
    {
        if (dog)
            idea = dog->getBrain()->get(i);
        else if (cat)
            idea = cat->getBrain()->get(i);
        if (idea == "")
            break ;
        else
            std::cout << type << " idea : " << idea << std::endl;
        i++;
    }
}

int main(void)
{
    Animal* objs[NB_ANIMALS + 1];
    Cat *c1 = new Cat();
    Dog *d1 = new Dog();
    Animal not_abstract_animal;

    std::cout << std::endl << "__________INIT__________" << std::endl;
    for (int i = 0; i < NB_ANIMALS; i++)
    {
        if (i > NB_ANIMALS / 2)
            objs[i] = new Cat();
        else
            objs[i] = new Dog();
    }
    std::cout << "___________SOME TESTS_________" << std::endl << std::endl;

    printTests(objs);
    c1->getBrain()->add("Is cpp easy to learn ?");
    c1->getBrain()->add("can I fly ?");
    c1->getBrain()->add("how bdd are working ?");
    d1->getBrain()->add("I'm hungry");
    d1->getBrain()->add("I prefer C over C++, woof");

    toMuchThinking(NULL, c1);
    toMuchThinking(d1, NULL);
    std::cout << "_____________________________" << std::endl << std::endl;

    for (int j = 0; j < NB_ANIMALS; j++)
        delete objs[j];
    delete c1;
    delete d1;
    return (0);
}
