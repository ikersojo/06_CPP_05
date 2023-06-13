/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isojo-go <isojo-go@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 23:18:15 by isojo-go          #+#    #+#             */
/*   Updated: 2023/06/13 23:18:19 by isojo-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Intern.hpp"

// Constructors:
/* ************************************************************************** */

Intern::Intern(void)
{
	if (DEBUG == 1)
		std::cout << "\033[0;93m" << "Default Intern Constructor called"
					<< "\033[0;39m" << std::endl;
}

Intern::Intern(const Intern& obj)
{
	if (DEBUG == 1)
		std::cout << "\033[0;93m" << "Copy Intern Constructor called"
					<< "\033[0;39m" << std::endl;
	*this = obj;
}

// Destructor:
/* ************************************************************************** */

Intern::~Intern(void)
{
	if (DEBUG == 1)
		std::cout << "\033[0;93m" << "Default Intern Destructor called"
					<< "\033[0;39m" << std::endl;
}

// Operator Override:
/* ************************************************************************** */

Intern&	Intern::operator=(const Intern& rhs)
{
	(void)rhs;
	return (*this);
}

// Member functions:
/* ************************************************************************** */

AForm*	Intern::makeForm(const std::string formName, const std::string target)
{
	int		i;
	AForm*	form;
	std::string	validForms[] = {"shrubbery creation", "robotomy request", "presidential pardon"};

	i = -1;
	while (++i < 3)
	{
		if (validForms[i] == formName)
			break;
	}
	try
	{
		switch (i)
		{
			case 0:
				form = new ShrubberyCreationForm(target);
				break;
			case 1:
				form = new RobotomyRequestForm(target);
				break;
			case 2:
				form = new PresidentialPardonForm(target);
				break;
			default:
				form = NULL;
				throw NonValidFormException();
		}
	}
	catch (const NonValidFormException& e)
	{
		std::cout << "\033[0;31m" << "Error: " << e.what() << "\033[0;39m" << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << "\033[0;31m" << "Error: " << e.what() << "\033[0;39m" << std::endl;
	}
	return (form);
}

// Exceptions:
/* ************************************************************************** */

const char* Intern::NonValidFormException::what() const throw()
{
	return ("The form name is not valid!");
}

// Stream operator overload to print Intern Class instances:
/* ************************************************************************** */

std::ostream&	operator<<(std::ostream& os, const Intern& obj)
{
	(void)obj;
	os << "just an intern";
	return (os);
}
