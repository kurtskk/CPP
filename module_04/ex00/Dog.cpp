#include "Dog.hpp"

Dog::Dog()
{
	_type = "Dog";
	std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog(const Dog &src) : Animal(src)
{
	std::cout << "Dog copy constructor called" << std::endl;
}

Dog &Dog::operator=(const Dog &src)
{
	if (this != &src)
	{
		std::cout << "Dog operator constructor called" << std::endl;
		_type = src._type;
	}
	return *this;
}

Dog::~Dog()
{
	std::cout << "Dog Destructor called" << std::endl;
}

void Dog::makeSound() const
{
	std::cout << "Wolf Wolf" << std::endl;
}