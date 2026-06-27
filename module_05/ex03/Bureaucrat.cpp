#include "Bureaucrat.hpp"

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Error: grade too high (minimum is 1)";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Error: grade too low (maximum is 150)";
}


Bureaucrat::Bureaucrat() : _name("Default"), _grade(150)
{
}

Bureaucrat::Bureaucrat(const std::string& name, int grade) : _name(name), _grade(grade)
{
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : _name(other._name), _grade(other._grade)
{
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat& other)
{
	if (this != &other)
	{
		_grade = other._grade;
	}
	return *this;
}

Bureaucrat::~Bureaucrat()
{
}

const std::string& Bureaucrat::getName() const
{
	return _name;
}

int Bureaucrat::getGrade() const
{
	return _grade;
}

void Bureaucrat::incrementGrade()
{
	if (_grade - 1 < 1)
		throw GradeTooHighException();
	_grade--;
}

void Bureaucrat::decrementGrade()
{
	if (_grade + 1 > 150)
		throw GradeTooLowException();
	_grade++;
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b)
{
    os << b.getName() << ", bureaucrat with classification " << b.getGrade();
    return os;
}

void Bureaucrat::signForm(AForm& form)
{
	    try
    {
        form.beSigned(*this);
        std::cout << _name
                  << " signed "
                  << form.getName()
                  << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << _name
                  << " couldn't sign "
                  << form.getName()
                  << " because "
                  << e.what()
                  << std::endl;
    }
}


void Bureaucrat::executeForm(AForm const &form)
{
	try
    {
        form.execute(*this);
        std::cout << _name
                  << " executed "
                  << form.getName()
                  << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << _name
                  << " couldn't execute "
                  << form.getName()
                  << " because "
                  << e.what()
                  << std::endl;
    }
}
