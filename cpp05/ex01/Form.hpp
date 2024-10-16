#pragma once

#include "Bureaucrat.hpp"

#include <iostream>
#include <exception>

class Bureaucrat;

class Form
{
	public:
		Form(const Form &o);
		~Form(void);

		Form(const std::string &name, unsigned int sign_grade, unsigned int execute_grade);

		Form	&operator=(const Form &o);

		void	beSigned(const Bureaucrat &bureaucrat);

		const std::string	&getName(void) const;
		bool				isSigned(void) const;
		unsigned int		getSignGrade(void) const;
		unsigned int		getExecuteGrade(void) const;

	private:
		Form(void);

		void	log_sign_failure(const Bureaucrat &bureaucrat, const std::string &msg) const;

	private:
		const std::string	m_name;
		const unsigned int	m_sign_grade;
		const unsigned int	m_execute_grade;
		bool				m_signed;

	public:
		class GradeTooHighException :
			public std::exception
		{
			virtual const char*	what() const throw();
		};

		class GradeTooLowException :
			public std::exception
		{
			virtual const char*	what() const throw();
		};
};

std::ostream	&operator<<(std::ostream &stream, const Form &form);
