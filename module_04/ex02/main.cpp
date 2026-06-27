#include "WrongAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"
#include "AAnimal.hpp"

int main()
{
    std::cout << "\n=== Normal test ===" << std::endl;
    const AAnimal* j = new Dog();
    const AAnimal* i = new Cat();
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    i->makeSound();
    j->makeSound();
    delete j;
    delete i;
    
    std::cout << "\n=== deep copy test ===" << std::endl;
    Dog a;
    Dog b(a);
    Dog c;
    c = a;
}
