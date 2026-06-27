#include "iter.hpp"

void printtest(const int& f)
{
	std::cout << f << std::endl;
}

void printstring(const std::string& x)
{
	std::cout << x << std::endl;
}

int main(void)
{
	int array[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	std::string list[3] = {"bob", "barry", "allen"};	
	iter(array, 10, printtest);
	iter(list, 3, printstring);
}
