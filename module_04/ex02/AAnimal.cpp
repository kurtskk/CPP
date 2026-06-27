#include "AAnimal.hpp"

AAnimal::AAnimal() : _type("Animal")
{
	std::cout << "Animal default constructor called" << std::endl;
}


AAnimal::AAnimal(const AAnimal &src)
{
	std::cout << "Animal copy constructor called" << std::endl;
	*this = src;
}

AAnimal &AAnimal::operator=(const AAnimal &src)
{
	if (this != &src)
	{
		std::cout << "Animal operator constructor called" << std::endl;
		_type = src._type;
	}
	return *this;
}

AAnimal::~AAnimal()
{
	std::cout << "Animal Destructor called" << std::endl;
}

std::string AAnimal::getType() const
{
	return _type;
}
