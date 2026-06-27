#include "ClapTrap.hpp"

int main(void)
{
  ClapTrap a("Max");
  ClapTrap b;

  a.attack("Robert");
  a.takeDamage(3);
  a.beRepaired(2);

  a.takeDamage(10);
  a.attack("Robert");
  a.beRepaired(5);

  return 0;

}