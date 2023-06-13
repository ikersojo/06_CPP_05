/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isojo-go <isojo-go@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 23:15:15 by isojo-go          #+#    #+#             */
/*   Updated: 2023/06/12 23:15:16 by isojo-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ShrubberyCreationForm.hpp"

// Constructors:
/* ************************************************************************** */

ShrubberyCreationForm::ShrubberyCreationForm(void) : AForm("ShrubberyCreationForm", false,  145, 137)
{
	if (DEBUG == 1)
		std::cout << "\033[0;93m" << "Default ShrubberyCreationForm Constructor called (" << this->getName()
					<< ")." << "\033[0;39m" << std::endl;
	this->_target = "undefined target";
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target) : AForm("ShrubberyCreationForm", false, 145, 137)
{
	if (DEBUG == 1)
		std::cout << "\033[0;93m" << "Named ShrubberyCreationForm Constructor called (" << this->getName()
					<< ")." << "\033[0;39m" << std::endl;
	this->_target = target;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& obj) : AForm("ShrubberyCreationForm", false, 145, 137), _target(obj.getTarget())
{
	if (DEBUG == 1)
		std::cout << "\033[0;93m" << "Copy ShrubberyCreationForm Constructor called (" << obj.getName()
					<< ")." << "\033[0;39m" << std::endl;
}

// Destructor:
/* ************************************************************************** */

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
	if (DEBUG == 1)
		std::cout << "\033[0;93m" << "Default ShrubberyCreationForm Destructor called (" << this->getName()
					<< ")." << "\033[0;39m" << std::endl;
}

// Operator Override:
/* ************************************************************************** */

ShrubberyCreationForm&	ShrubberyCreationForm::operator=(const ShrubberyCreationForm& rhs)
{
	if (this != &rhs)
	{
		this->~ShrubberyCreationForm();
		new(this) ShrubberyCreationForm(rhs.getTarget());
		this->setSignatureStatus(rhs.getSignatureStatus());
	}
	return (*this);
}

// Member functions:
/* ************************************************************************** */

std::string	ShrubberyCreationForm::getTarget(void) const
{
	return (this->_target);
}

void	ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	if (this->checkExecute(executor) == true)
	{
		std::string		name = this->getTarget() + "_shrubbery";
		std::ofstream	outFile(name);

		if (outFile.is_open())
		{
			outFile << std::endl;
			outFile << "               ,@@@@@@@," << std::endl;
			outFile << "       ,,,.   ,@@@@@@/@@,  .oo8888o." << std::endl;
			outFile << "    ,&&&&%&&%,@@@@@/@@@@@@,8888888/8o" << std::endl;
			outFile << "   ,%&&&&&%&&%,@@@@@@@/@@@88888888/88'" << std::endl;
			outFile << "   %&&%&%&/%&&%@@@@@/ /@@@88888888888'" << std::endl;
			outFile << "   %&&%/ %&&&&&@@\\ V /@@' `8888 `/88'" << std::endl;
			outFile << "   `&%\\ ` /%&'    |.|        \\ '|8'" << std::endl;
			outFile << "       |o|        | |         | |" << std::endl;
			outFile << "       |.|        | |         | |" << std::endl;
			outFile << "... \\// ._\\//_/__//  ,\\_//__\\//.  \\_//__/_" << std::endl;
			outFile << std::endl;
			outFile.close();
			std::cout << "\033[0;96m" << name << " file generated." << "\033[0;39m" << std::endl;
		}
		else
			std::cout << "Failed to open the file." << std::endl;
	}
}
