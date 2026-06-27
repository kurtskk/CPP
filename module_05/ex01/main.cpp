#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    std::cout << "--- test 1: bureaucrat with good grade signs the form ---" << std::endl;
    try
    {
        Bureaucrat bob("Bob", 10);
        Form       contract("Contract", 50, 50);

        std::cout << contract << std::endl;
        bob.signForm(contract);
        std::cout << contract << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }


    std::cout << "\n--- test 2: bureaucrat with low grade fails to sign ---" << std::endl;
    try
    {
        Bureaucrat bob("Bob", 100);
        Form       contract("Contract", 10, 10);

        bob.signForm(contract);
    }
    catch (std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }


    std::cout << "\n--- test 3: form with invalid grade ---" << std::endl;
    try
    {
        Form contract("Contract", 0, 50);
    }
    catch (std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }

    return 0;
}