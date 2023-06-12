/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isojo-go <isojo-go@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 19:37:43 by isojo-go          #+#    #+#             */
/*   Updated: 2023/06/12 22:50:02 by isojo-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/PresidentialPardonForm.hpp"

// Constructors:
/* ************************************************************************** */

PresidentialPardonForm::PresidentialPardonForm(void) : AForm("PresidentialPardonForm", false,  25, 5)
{
	if (DEBUG == 1)
		std::cout << "\033[0;93m" << "Default PresidentialPardonForm Constructor called (" << this->getName()
					<< ")." << "\033[0;39m" << std::endl;
	this->_target = "undefined target";
}

PresidentialPardonForm::PresidentialPardonForm(const std::string target) : AForm("PresidentialPardonForm", false, 25, 5)
{
	if (DEBUG == 1)
		std::cout << "\033[0;93m" << "Named PresidentialPardonForm Constructor called (" << this->getName()
					<< ")." << "\033[0;39m" << std::endl;
	this->_target = target;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& obj) : AForm("PresidentialPardonForm", false, 25, 5), _target(obj.getTarget())
{
	if (DEBUG == 1)
		std::cout << "\033[0;93m" << "Copy PresidentialPardonForm Constructor called (" << obj.getName()
					<< ")." << "\033[0;39m" << std::endl;
}

// Destructor:
/* ************************************************************************** */

PresidentialPardonForm::~PresidentialPardonForm(void)
{
	if (DEBUG == 1)
		std::cout << "\033[0;93m" << "Default PresidentialPardonForm Destructor called (" << this->getName()
					<< ")." << "\033[0;39m" << std::endl;
}

// Operator Override:
/* ************************************************************************** */

PresidentialPardonForm&	PresidentialPardonForm::operator=(const PresidentialPardonForm& rhs)
{
	if (this != &rhs)
	{
		this->~PresidentialPardonForm();
		new(this) PresidentialPardonForm(rhs.getTarget());
		this->setSignatureStatus(rhs.getSignatureStatus());
	}
	return (*this);
}

// Member functions:
/* ************************************************************************** */

std::string	PresidentialPardonForm::getTarget(void) const
{
	return (this->_target);
}

void	PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	if (this->checkExecute(executor) == true)
		std::cout << "\033[0;96m" << this->getTarget() << " pardoned by President Zaphod Beeblebrox." << "\033[0;39m" << std::endl;
}
