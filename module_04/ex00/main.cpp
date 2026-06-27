#include "WrongAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"
#include "Animal.hpp"


int main()
{
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    i->makeSound();
    j->makeSound();
    meta->makeSound();

    std::cout << "\n=== Wrong Animals ===" << std::endl;
    const WrongAnimal* meta1 = new WrongAnimal();
    const WrongAnimal* i1 = new WrongCat();
    std::cout << i1->getType() << " " << std::endl;
    i1->makeSound();
    meta1->makeSound();
    delete meta;
    delete j;
    delete i;
    delete meta1;
    delete i1;

    return 0;
}