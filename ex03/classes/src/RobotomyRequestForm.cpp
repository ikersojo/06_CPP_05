/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isojo-go <isojo-go@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 22:53:47 by isojo-go          #+#    #+#             */
/*   Updated: 2023/06/12 22:53:58 by isojo-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/RobotomyRequestForm.hpp"

// Constructors:
/* ************************************************************************** */

RobotomyRequestForm::RobotomyRequestForm(void) : AForm("RobotomyRequestForm", false,  72, 45)
{
	if (DEBUG == 1)
		std::cout << "\033[0;93m" << "Default RobotomyRequestForm Constructor called (" << this->getName()
					<< ")." << "\033[0;39m" << std::endl;
	this->_target = "undefined target";
}

RobotomyRequestForm::RobotomyRequestForm(const std::string target) : AForm("RobotomyRequestForm", false, 72, 45)
{
	if (DEBUG == 1)
		std::cout << "\033[0;93m" << "Named RobotomyRequestForm Constructor called (" << this->getName()
					<< ")." << "\033[0;39m" << std::endl;
	this->_target = target;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& obj) : AForm("RobotomyRequestForm", false, 72, 45), _target(obj.getTarget())
{
	if (DEBUG == 1)
		std::cout << "\033[0;93m" << "Copy RobotomyRequestForm Constructor called (" << obj.getName()
					<< ")." << "\033[0;39m" << std::endl;
}

// Destructor:
/* ************************************************************************** */

RobotomyRequestForm::~RobotomyRequestForm(void)
{
	if (DEBUG == 1)
		std::cout << "\033[0;93m" << "Default RobotomyRequestForm Destructor called (" << this->getName()
					<< ")." << "\033[0;39m" << std::endl;
}

// Operator Override:
/* ************************************************************************** */

RobotomyRequestForm&	RobotomyRequestForm::operator=(const RobotomyRequestForm& rhs)
{
	if (this != &rhs)
	{
		this->~RobotomyRequestForm();
		new(this) RobotomyRequestForm(rhs.getTarget());
		this->setSignatureStatus(rhs.getSignatureStatus());
	}
	return (*this);
}

// Member functions:
/* ************************************************************************** */

std::string	RobotomyRequestForm::getTarget(void) const
{
	return (this->_target);
}

void	RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	if (this->checkExecute(executor) == true)
	{
		std::cout << "\033[0;96m" << "... some drilling noise ..." << "\033[0;39m" << std::endl;
		int	random_num = rand();
		if (random_num % 2)
			std::cout << "\033[0;96m" << this->getTarget() << " succesfully robotimized!"
						<< "\033[0;39m" << std::endl;
		else
			std::cout << "\033[0;31m" << "Robotomy failed on " << this->getTarget() << "!"
						<< "\033[0;39m" << std::endl;
	}
}
