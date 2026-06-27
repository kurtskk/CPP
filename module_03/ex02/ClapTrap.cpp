#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
	: _name("Default"), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) 
	: _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap " << name <<  " constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &src)
{
	std::cout << "ClapTrap " << src._name <<  " copy constructor called" << std::endl;
	_name = src._name;
	_hitPoints = src._hitPoints;
	_energyPoints = src._energyPoints;
	_attackDamage = src._attackDamage;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &src)
{
	if (this != &src)
	{
		std::cout << "ClapTrap " << src._name <<  " operator constructor called" << std::endl;
		_name = src._name;
		_hitPoints = src._hitPoints;
		_energyPoints = src._energyPoints;
		_attackDamage = src._attackDamage;
	}
	return *this;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << _name <<  " Destructor called" << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
	if (_energyPoints == 0 || _hitPoints == 0)
		std::cout << "ClapTrap " << _name << " Can't attack" << std::endl;
	else
	{
		std::cout << "ClapTrap " << _name << " attacks " << target << " causing "  << _attackDamage << " points of damage!" << std::endl;
		_energyPoints -= 1;
	}
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (_hitPoints == 0)
		std::cout << "ClapTrap " << _name << " is already dead" << std::endl;
	else
	{
		std::cout << "ClapTrap " << _name << " takes " << amount << " Points damage" << std::endl;
		if (amount >= _hitPoints)
			_hitPoints = 0;
		else
			_hitPoints -= amount;
	}
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (_energyPoints == 0 || _hitPoints == 0)
	{
		std::cout << "ClapTrap " << _name << " Can't be repaired" << std::endl;
	}
	else
	{
		std::cout << "ClapTrap " << _name << " was repaired " <<  amount << " hit points! " << std::endl;
		_hitPoints += amount;
		_energyPoints -= 1;
	}
}