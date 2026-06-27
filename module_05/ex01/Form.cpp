#include "Form.hpp"
#include "Bureaucrat.hpp"


const char* Form::GradeTooHighExpection::what() const throw()
{
	return "Error: form grade too high (minimum is 1)";
}

const char* Form::GradeTooLowExpection::what() const throw()
{
	return "Error: form grade too low (maximum is 150)";
}

Form::Form() : _name("Default"), _signed(false), _gradeToSign(150), _gradeToExecute(150)
{
}

Form::Form(const std::string& name, int gradeToSign, int gradeToExecute) : _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	if (gradeToExecute < 1 || gradeToSign < 1)
		throw GradeTooHighExpection();
	if (gradeToExecute > 150 || gradeToSign > 150)
		throw GradeTooLowExpection();
}

Form::Form(const Form& other) : 
	_name(other._name),
    _signed(other._signed),
    _gradeToSign(other._gradeToSign),
    _gradeToExecute(other._gradeToExecute)
{
}

Form &Form::operator=(const Form& other)
{
	if (this != &other)
	{
		_signed = other._signed;
	}
	return *this;
}

Form::~Form()
{
}

const std::string& Form::getName() const
{
	return _name;
}

bool Form::getSigned() const
{
	return _signed;
}

int Form::getGradeToSign() const
{
	return _gradeToSign;
}

int Form::getGradeToExecute() const
{
	return _gradeToExecute;
}

void Form::beSigned(const Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() > _gradeToSign)
		throw GradeTooLowExpection();
	_signed = true;
}

std::ostream& operator<<(std::ostream& os, const Form& f)
{
    os << "Form name:          " << f.getName()                            << std::endl;
    os << "Signed:             " << (f.getSigned() ? "yes" : "no")        << std::endl;
    os << "Grade to sign:      " << f.getGradeToSign()                    << std::endl;
    os << "Grade to execute:   " << f.getGradeToExecute()                 << std::endl;

    return os;
}

