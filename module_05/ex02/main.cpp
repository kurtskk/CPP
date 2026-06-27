#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
    std::cout << "--- test 1: shrubbery form ---" << std::endl;
    try
    {
        Bureaucrat            bob("Bob", 136);
        ShrubberyCreationForm form("home");

        bob.signForm(form);
        bob.executeForm(form);
    }
    catch (std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }


    std::cout << "\n--- test 2: execute without signing ---" << std::endl;
    try
    {
        Bureaucrat          bob("Bob", 1);
        RobotomyRequestForm form("Alice");

        bob.executeForm(form);
    }
    catch (std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }


    std::cout << "\n--- test 3: robotomy form ---" << std::endl;
    try
    {
        Bureaucrat          bob("Bob", 45);
        RobotomyRequestForm form("Alice");

        bob.signForm(form);
        bob.executeForm(form);
        bob.executeForm(form);
    }
    catch (std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }


    std::cout << "\n--- test 4: presidential pardon ---" << std::endl;
    try
    {
        Bureaucrat             bob("Bob", 5);
        PresidentialPardonForm form("Carol");

        bob.signForm(form);
        bob.executeForm(form);
    }
    catch (std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }


    std::cout << "\n--- test 5: grade too low to sign ---" << std::endl;
    try
    {
        Bureaucrat             bob("Bob", 100);
        PresidentialPardonForm form("Carol");

        bob.signForm(form);
        bob.executeForm(form);
    }
    catch (std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }

    return 0;
}