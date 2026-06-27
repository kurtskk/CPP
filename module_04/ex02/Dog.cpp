#include "Dog.hpp"

Dog::Dog()
{
	_brain = new Brain();
	_type = "Dog";
	std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog(const Dog &src) : AAnimal(src)
{
	_brain = new Brain(*src._brain);
	std::cout << "Dog copy constructor called" << std::endl;
}

Dog &Dog::operator=(const Dog &src)
{
	if (this != &src)
	{
		_type = src._type;
		delete _brain;
		_brain = new Brain(*src._brain);
		std::cout << "Dog operator constructor called" << std::endl;
	}
	return *this;
}

Dog::~Dog()
{
	delete _brain;
	std::cout << "Dog Destructor called" << std::endl;
}

void Dog::makeSound() const
{
	std::cout << "Wolf Wolf" << std::endl;
}