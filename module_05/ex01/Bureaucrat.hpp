#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <iostream>
#include <exception>
#include "Form.hpp"



class Bureaucrat
{
	private:
		const std::string _name;
		int _grade;

	public:


		class GradeTooHighExpection : public std::exception
		{
			public:
				const char* what() const throw();
		};

		class GradeTooLowExpection : public std::exception
		{
			public:
				const char* what() const throw();
		};

		Bureaucrat();
		Bureaucrat(const std::string& name, int grade);
		Bureaucrat(const Bureaucrat& other);
		Bureaucrat& operator=(const Bureaucrat& other);
		~Bureaucrat();

		const std::string& getName() const;
		int				  getGrade() const;


		void incrementGrade();
		void decrementGrade();
		void signForm(Form &Form);

};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);

#endif