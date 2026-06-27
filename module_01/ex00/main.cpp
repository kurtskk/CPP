#include "Zombie.hpp"

int main()
{
	Zombie* heapZombie = newZombie("heapZombie");
	heapZombie->announce();
	delete heapZombie;

	std::cout << "-----------------" << std::endl;
	randomChump("StackZombie");

	return 0;
}