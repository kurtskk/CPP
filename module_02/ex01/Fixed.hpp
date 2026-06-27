#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
	private:
		int _value;
		static const int _fractionalBits = 8;

	public:
		Fixed();
		Fixed(const int n);
		Fixed(const float f);
		Fixed(const Fixed &src);
		Fixed &operator=(const Fixed &src);
		~Fixed();

		int     getRawBits(void) const;
        void    setRawBits(int const raw);
		int 	toInt( void ) const;
		float 	toFloat( void ) const;
};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif
