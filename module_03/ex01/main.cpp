#include "ScavTrap.hpp"

int main()
{
    ScavTrap a("Robert");
    ScavTrap d;

    a.attack("max");
    a.takeDamage(10);
    a.beRepaired(5);
    a.guardGate();

    ScavTrap b(a);
    ScavTrap c;
    c = a;

    return 0;
}