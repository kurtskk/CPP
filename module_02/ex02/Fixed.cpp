#include "Fixed.hpp"

Fixed::Fixed() : _value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int n) : _value(n << _fractionalBits)
{
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float f) : _value(roundf(f * (1 << _fractionalBits)))
{
	std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &src)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Fixed &Fixed::operator=(const Fixed &src)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &src)
		_value = src._value;
	return *this;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return _value;
}

void Fixed::setRawBits(int const raw)
{
	_value = raw;
}

int Fixed::toInt(void) const
{
	return _value >> 8;
}

float Fixed::toFloat(void) const
{
	return (float)_value / (1 << _fractionalBits);
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
	out << fixed.toFloat();
	return out;
}

Fixed &Fixed::operator++()
{
	_value = _value + 1;
	return *this;
}

Fixed Fixed::operator++(int)
{
	Fixed tmp(*this);
	_value = _value + 1;
	return tmp;
}
Fixed &Fixed::operator--()
{
	_value = _value - 1;
	return *this;
}

Fixed Fixed::operator--(int)
{
	Fixed tmp(*this);
	_value = _value - 1;
	return tmp;
}

Fixed Fixed::operator+(const Fixed &src) const
{
	Fixed n;
	n.setRawBits(_value + src._value);
	return n;
}

Fixed Fixed::operator-(const Fixed &src) const
{
	Fixed n;
	n.setRawBits(_value - src._value);
	return n;
}

Fixed Fixed::operator*(const Fixed &src) const
{
	Fixed n;
	n.setRawBits(((long long)_value * src._value) >> _fractionalBits);
	return n;
}

Fixed Fixed::operator/(const Fixed &src) const
{
	Fixed n;
	n.setRawBits(((long long)_value << _fractionalBits) / src._value);
	return n;
}

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
	if (a < b)
		return a;
	return b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
	if (a > b)
		return a;
	return b;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
	if (a < b)
		return a;
	return b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
	if (a > b)
		return a;
	return b;
}

bool Fixed::operator>(const Fixed &src) const
{
	return _value > src._value;
}

bool Fixed::operator<(const Fixed &src) const
{
	return _value < src._value;
}

bool Fixed::operator>=(const Fixed &src) const
{
	return _value >= src._value;
}

bool Fixed::operator<=(const Fixed &src) const
{
	return _value <= src._value;
}

bool Fixed::operator==(const Fixed &src) const
{
	return _value == src._value;
}

bool Fixed::operator!=(const Fixed &src) const
{
	return _value != src._value;
}