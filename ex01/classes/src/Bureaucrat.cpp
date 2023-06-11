/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isojo-go <isojo-go@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 20:56:22 by isojo-go          #+#    #+#             */
/*   Updated: 2023/06/11 11:04:30 by isojo-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"

// Constructors:
/* ************************************************************************** */

Bureaucrat::Bureaucrat(void) : _name("un-named"), _grade(MIN_GRADE)
{
	if (DEBUG == 1)
		std::cout << "\033[0;93m" << "Default Constructor called (" << this->getName()
					<< ")." << "\033[0;39m" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string name, const int grade) : _name(name), _grade(grade)
{
	if (DEBUG == 1)
		std::cout << "\033[0;93m" << "Nanmed Constructor called (" << this->getName()
					<< ")." << "\033[0;39m" << std::endl;
	Bureaucrat::checkGrade();
}

Bureaucrat::Bureaucrat(const Bureaucrat& obj)
{
	if (DEBUG == 1)
		std::cout << "\033[0;93m" << "Copy Constructor called (" << obj.getName()
					<< ")." << "\033[0;39m" << std::endl;
	*this = obj;
}

// Destructor:
/* ************************************************************************** */

Bureaucrat::~Bureaucrat(void)
{
	if (DEBUG == 1)
		std::cout << "\033[0;93m" << "Default Destructor called (" << this->getName()
					<< ")." << "\033[0;39m" << std::endl;
}

// Operator Override:
/* ************************************************************************** */

Bureaucrat&	Bureaucrat::operator=(const Bureaucrat& rhs)
{
	if (this != &rhs)
	{
		this->~Bureaucrat();
		new(this) Bureaucrat(rhs.getName(), rhs.getGrade());
	}
	return (*this);
}

// Member functions:
/* ************************************************************************** */

const std::string&	Bureaucrat::getName(void) const
{
	return (this->_name);
}

int	Bureaucrat::getGrade(void) const
{
	return (this->_grade);
}

void	Bureaucrat::incrementGrade(void)
{
	this->_grade--;
	Bureaucrat::checkGrade();
}

void	Bureaucrat::decrementGrade(void)
{
	this->_grade++;
	Bureaucrat::checkGrade();
}

void	Bureaucrat::signForm(Form& form)
{
	try
	{
		if (form.getSignatureStatus() == false)
		{
			if (this->getGrade() >= form.getReqGradeForSign())
			{
				form.beSigned(*this);
				std::cout << this->getName() << " signed " << form.getName() << std::endl;
			}
			else
			{
				std::cout << this->getName() << " coudn't sign " << form.getName()
					<< " because it is already signed"<< std::endl;
				throw GradeTooLowException();
			}
		}
		else
			std::cout << this->getName() << " coudn't sign " << form.getName()
				<< " because it is already signed"<< std::endl;
	}
	catch (const GradeTooLowException& e)
	{
		std::cout << "\033[0;31m" << "Error: " << e.what() << "\033[0;39m" << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << "\033[0;31m" << "Error: " << e.what() << "\033[0;39m" << std::endl;
	}

}

// Exceptions:
/* ************************************************************************** */

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("The grade is too high!");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("The grade is too low!");
}

void	Bureaucrat::checkGrade(void)
{
	try
	{
		if (this->_grade < MAX_GRADE)
			throw GradeTooHighException();
		else if (this->_grade > MIN_GRADE)
			throw GradeTooLowException();
	}
	catch (const GradeTooHighException& e)
	{
		std::cout << "\033[0;31m" << "Error: " << e.what() << "\033[0;39m" << std::endl;
		this->_grade = MAX_GRADE;
	}
	catch (const GradeTooLowException& e)
	{
		std::cout << "\033[0;31m" << "Error: " << e.what() << "\033[0;39m" << std::endl;
		this->_grade = MIN_GRADE;
	}
	catch (const std::exception& e)
	{
		std::cout << "\033[0;31m" << "Error: " << e.what() << "\033[0;39m" << std::endl;
	}
}

// Stream operator overload to print Bureaucrat Class instances:
/* ************************************************************************** */

std::ostream&	operator<<(std::ostream& os, const Bureaucrat& obj)
{
	os << obj.getName() << " (bureaucrat grade " << obj.getGrade() << ")";
	return (os);
}
