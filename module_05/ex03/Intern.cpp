#include "Intern.hpp"

Intern::Intern()
{
}

Intern::Intern(const Intern& other)
{
    (void)other;
}

Intern& Intern::operator=(const Intern& other)
{
    (void)other;
    return *this;
}

Intern::~Intern()
{
}

static AForm* createShrubbery(const std::string& target)
{
    return new ShrubberyCreationForm(target);
}

static AForm* createRobotomy(const std::string& target)
{
    return new RobotomyRequestForm(target);
}

static AForm* createPardon(const std::string& target)
{
    return new PresidentialPardonForm(target);
}

struct FormType
{
    std::string name;
    AForm*      (*create)(const std::string& target);
};

AForm* Intern::makeForm(const std::string& name, const std::string& target) const
{
    FormType forms[] = {
        {"shrubbery creation",   createShrubbery},
        {"robotomy request",     createRobotomy},
        {"presidential pardon",  createPardon}
    };

    int size = 3;
    for (int i = 0; i < size; i++)
    {
        if (forms[i].name == name)
        {
            std::cout << "Intern creates " << name << std::endl;
            return forms[i].create(target);
        }
    }

    std::cout << "Error: form '" << name << "' does not exist" << std::endl;
    return NULL;
}