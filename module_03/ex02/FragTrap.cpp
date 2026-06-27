#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
	_hitPoints = 100;
    _energyPoints = 100;
    _attackDamage = 30;
    std::cout << "FragTrap default constructor called" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	_hitPoints = 100;
    _energyPoints = 100;
    _attackDamage = 30;
    std::cout << "FragTrap " << _name << " constructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap &src) : ClapTrap(src)
{
	std::cout << "FragTrap " << src._name <<  " copy constructor called" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &src)
{
	if (this != &src)
	{
		ClapTrap::operator=(src);
		std::cout << "FragTrap " << src._name <<  " operator constructor called" << std::endl;
	}
	return *this;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap " << _name <<  " Destructor called" << std::endl;
}

void FragTrap::attack(const std::string& target)
{
	if (_energyPoints == 0 || _hitPoints == 0)
		std::cout << "FragTrap " << _name << " Can't attack" << std::endl;
	else
	{
		std::cout << "FragTrap " << _name << " attacks " << target << " causing "  << _attackDamage << " points of damage!" << std::endl;
		_energyPoints -= 1;
	}
}

void	FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap requests a high five!" << std::endl;
}