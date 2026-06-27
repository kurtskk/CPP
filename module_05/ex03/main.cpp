#include "Bureaucrat.hpp"
#include "Intern.hpp"

int main()
{
    Intern intern;

    std::cout << "--- test 1: create shrubbery form ---" << std::endl;
    {
        AForm* form = intern.makeForm("shrubbery creation", "home");
        if (form)
        {
            Bureaucrat bob("Bob", 136);
            bob.signForm(*form);
            bob.executeForm(*form);
            delete form;
        }
    }

    std::cout << "\n--- test 2: create robotomy form ---" << std::endl;
    {
        AForm* form = intern.makeForm("robotomy request", "Bender");
        if (form)
        {
            Bureaucrat bob("Bob", 45);
            bob.signForm(*form);
            bob.executeForm(*form);
            delete form;
        }
    }

    std::cout << "\n--- test 3: create presidential pardon ---" << std::endl;
    {
        AForm* form = intern.makeForm("presidential pardon", "Carol");
        if (form)
        {
            Bureaucrat bob("Bob", 5);
            bob.signForm(*form);
            bob.executeForm(*form);
            delete form;
        }
    }

    std::cout << "\n--- test 4: invalid form ---" << std::endl;
    {
        AForm* form = intern.makeForm("invalid form", "target");
        if (form)
            delete form;
    }

    return 0;
}