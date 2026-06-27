#include "WrongAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"
#include "Animal.hpp"

int main()
{
    std::cout << "\n=== Normal test ===" << std::endl;
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    i->makeSound();
    j->makeSound();
    meta->makeSound();
    delete meta;
    delete j;
    delete i;

    std::cout << "\n=== Array test ===" << std::endl;
    Animal* animals[10];
    for (int i = 0; i < 5; i++)
        animals[i] = new Dog();
    for (int i = 5; i < 10; i++)
        animals[i] = new Cat();
    for (int i = 0; i < 10; i++)
        delete animals[i];
    
    std::cout << "\n=== deep copy test ===" << std::endl;
    Dog a;
    Dog b(a);
    Dog c;

    c = a;
}
