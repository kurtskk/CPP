#include "Span.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

int main()
{
    std::cout << "--- test 1: subject example ---" << std::endl;
    try
    {
        Span sp(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }


    std::cout << "\n--- test 2: span full ---" << std::endl;
    try
    {
        Span sp(3);
        sp.addNumber(1);
        sp.addNumber(2);
        sp.addNumber(3);
        sp.addNumber(4);
    }
    catch (std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }


    std::cout << "\n--- test 3: no span ---" << std::endl;
    try
    {
        Span sp(5);
        sp.addNumber(1);
        std::cout << sp.shortestSpan() << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }


    std::cout << "\n--- test 4: addRange ---" << std::endl;
    try
    {
        std::vector<int> v;
        v.push_back(10);
        v.push_back(5);
        v.push_back(20);
        v.push_back(1);
        v.push_back(15);

        Span sp(5);
        sp.addRange(v.begin(), v.end());
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }


    std::cout << "\n--- test 5: 10000 numbers ---" << std::endl;
    try
    {
        std::srand(std::time(NULL));
        Span sp(10000);

        for (int i = 0; i < 10000; i++)
            sp.addNumber(std::rand());

        std::cout << "shortest: " << sp.shortestSpan() << std::endl;
        std::cout << "longest:  " << sp.longestSpan() << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }

    return 0;
}
