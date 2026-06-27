#include "Bureaucrat.hpp"

int main()
{
    std::cout << "---teste 1: criacao valida---" << std::endl;
    try
    {
        Bureaucrat bob("Bob", 75);

        std::cout << bob << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }


    std::cout << "\n---teste 2: grade invalida (0)---" << std::endl;
    try
    {
        Bureaucrat bob("Bob", 0);
    }
    catch (std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }


    std::cout << "\n---teste 3: grade invalida (151)---" << std::endl;
    try
    {
        Bureaucrat bob("Bob", 151);
    }
    catch (std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }


    std::cout << "\n---teste 4: incrementar alem do limite---" << std::endl;
    try
    {
        Bureaucrat bob("Bob", 1);

        std::cout << bob << std::endl;
        bob.incrementGrade();
    }
    catch (std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }


    std::cout << "\n---teste 5: decrementar alem do limite---" << std::endl;
    try
    {
        Bureaucrat bob("Bob", 150);

        std::cout << bob << std::endl;
        bob.decrementGrade();
    }
    catch (std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }

    return 0;
}