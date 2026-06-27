#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>

int main()
{
    std::cout << "--- test 1: found in vector ---" << std::endl;
    try
    {
        std::vector<int> v;
        v.push_back(1);
        v.push_back(2);
        v.push_back(3);
        v.push_back(42);
        v.push_back(5);

        std::vector<int>::iterator it = easyfind(v, 42);
        std::cout << "found: " << *it << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "\n--- test 2: not found in vector ---" << std::endl;
    try
    {
        std::vector<int> v;
        v.push_back(1);
        v.push_back(2);
        v.push_back(3);

        std::vector<int>::iterator it = easyfind(v, 99);
        std::cout << "found: " << *it << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "\n--- test 3: found in list ---" << std::endl;
    try
    {
        std::list<int> l;
        l.push_back(10);
        l.push_back(20);
        l.push_back(30);

        std::list<int>::iterator it = easyfind(l, 20);
        std::cout << "found: " << *it << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }

    return 0;
}