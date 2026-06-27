#include "Base.hpp"
#include <cstdlib>
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

int main(void)
{
    Base* p = generate();

    std::cout << "identify by pointer: ";
    identify(p);

    std::cout << "identify by reference: ";
    identify(*p);

    delete p;
    return 0;
}