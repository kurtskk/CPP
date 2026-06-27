#include "Cat.hpp"

Cat::Cat()
{
	_brain = new Brain();
	_type = "Cat";
	std::cout << "Cat default constructor called" << std::endl;
}

Cat::Cat(const Cat &src) : Animal(src)
{
	_brain = new Brain(*src._brain);
	std::cout << "Cat copy constructor called" << std::endl;
}

Cat &Cat::operator=(const Cat &src)
{
	if (this != &src)
	{
		_type = src._type;
		delete _brain;
		_brain = new Brain(*src._brain);
		std::cout << "Cat operator constructor called" << std::endl;
	}
	return *this;
}

Cat::~Cat()
{
	delete _brain;
	std::cout << "Cat Destructor called" << std::endl;
}

void Cat::makeSound() const
{
	std::cout << "Meow Meow" << std::endl;
}