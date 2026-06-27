#include "Base.hpp"
#include <ctime>
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base* generate(void)
{
    std::srand(std::time(NULL));
	int num = std::rand() % 3;

	if (num == 0)
		return new A();
	else if (num == 1)
		return new B();
	else
		return new C();
}

