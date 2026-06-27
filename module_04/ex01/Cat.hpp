#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include <iostream>
#include <string>
#include "Brain.hpp"

class Cat : public Animal
{

	private:
		Brain* _brain;
	public:
		Cat();
		Cat(const Cat &src);
		Cat &operator=(const Cat &src);
		~Cat();

		virtual void makeSound() const;
};

#endif