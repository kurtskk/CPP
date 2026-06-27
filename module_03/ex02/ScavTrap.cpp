#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
	_hitPoints = 100;
    _energyPoints = 50;
    _attackDamage = 20;
    std::cout << "ScavTrap default constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	_hitPoints = 100;
    _energyPoints = 50;
    _attackDamage = 20;
    std::cout << "ScavTrap " << _name << " constructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &src) : ClapTrap(src)
{
	std::cout << "ScavTrap " << src._name <<  " copy constructor called" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &src)
{
	if (this != &src)
	{
		ClapTrap::operator=(src);
		std::cout << "ScavTrap " << src._name <<  " operator constructor called" << std::endl;
	}
	return *this;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << _name <<  " Destructor called" << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
	if (_energyPoints == 0 || _hitPoints == 0)
		std::cout << "ScavTrap " << _name << " Can't attack" << std::endl;
	else
	{
		std::cout << "ScavTrap " << _name << " attacks " << target << " causing "  << _attackDamage << " points of damage!" << std::endl;
		_energyPoints -= 1;
	}
}

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << _name << " entered gatekeeper mode" << std::endl;
}