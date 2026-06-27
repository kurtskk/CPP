#include "Zombie.hpp"

int main()
{
    int N = 5;

    Zombie* horde = zombieHorde(N, "Carlos");

    if (!horde)
        return 1;

    for (int i = 0; i < N; i++)
    {
        horde[i].announce();
    }

    delete[] horde;

    return 0;
}
