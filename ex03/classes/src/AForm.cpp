/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isojo-go <isojo-go@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 23:18:05 by isojo-go          #+#    #+#             */
/*   Updated: 2023/06/13 23:18:19 by isojo-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/AForm.hpp"

// Constructors:
/* ************************************************************************** */

AForm::AForm(void) : _name("un-named"), _signedStatus(false), _reqGradeForSign(MIN_GRADE), _reqGradeForExec(MIN_GRADE)
{
	if (DEBUG == 1)
		std::cout << "\033[0;93m" << "Default AForm Constructor called (" << this->getName()
					<< ")." << "\033[0;39m" << std::endl;
}

AForm::AForm(const std::string name, bool signedStatus, const int reqGradeForSign, const int reqGradeForExec) :
			_name(name), _signedStatus(signedStatus), _reqGradeForSign(reqGradeForSign), _reqGradeForExec(reqGradeForExec)
{
	if (DEBUG == 1)
		std::cout << "\033[0;93m" << "Named AForm Constructor called (" << this->getName()
					<< ")." << "\033[0;39m" << std::endl;
	AForm::checkGrade();
}

AForm::AForm(const AForm& obj) : _name(obj.getName()), _signedStatus(obj.getSignatureStatus()),
			_reqGradeForSign(obj.getReqGradeForSign()), _reqGradeForExec(obj.getReqGradeForExec())
{
	if (DEBUG == 1)
		std::cout << "\033[0;93m" << "Copy AForm Constructor called (" << obj.getName()
					<< ")." << "\033[0;39m" << std::endl;
	*this = obj;
}

// Destructor:
/* ************************************************************************** */

AForm::~AForm(void)
{
	if (DEBUG == 1)
		std::cout << "\033[0;93m" << "Default AForm Destructor called (" << this->getName()
					<< ")." << "\033[0;39m" << std::endl;
}

// Operator Override:
/* ************************************************************************** */

AForm&	AForm::operator=(const AForm& rhs)
{
	if (this != &rhs)
	{
		this->_signedStatus = rhs.getSignatureStatus();
	}
	return (*this);
}

// Member functions:
/* ************************************************************************** */

const std::string&	AForm::getName(void) const
{
	return (this->_name);
}

bool	AForm::getSignatureStatus(void) const
{
	return (this->_signedStatus);
}

int	AForm::getReqGradeForSign(void) const
{
	return (this->_reqGradeForSign);
}

int	AForm::getReqGradeForExec(void) const
{
	return (this->_reqGradeForExec);
}

void	AForm::setSignatureStatus(bool status)
{
	this->_signedStatus = status;
}

void	AForm::beSigned(const Bureaucrat& bureaucrat)
{
	if (this->getSignatureStatus() == false)
	{
		if (bureaucrat.getGrade() <= this->getReqGradeForSign())
		{
			this->_signedStatus = true;
		}
	}
}

bool	AForm::checkExecute(Bureaucrat const & executor) const
{
	bool res;

	try
	{
		if (this->getSignatureStatus() == true)
		{
			if (executor.getGrade() <= this->getReqGradeForExec())
				res = true;
			else
			{
				res = false;
				throw GradeTooLowException();
			}
		}
		else
		{
			res = false;
			throw UnsignedFormException();
		}
	}
	catch (const UnsignedFormException& e)
	{
		std::cout << "\033[0;31m" << "Error: " << e.what() << "\033[0;39m" << std::endl;
	}
	catch (const GradeTooLowException& e)
	{
		std::cout << "\033[0;31m" << "Error: " << e.what() << "\033[0;39m" << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << "\033[0;31m" << "Error: " << e.what() << "\033[0;39m" << std::endl;
	}
	return (res);
}


// Exceptions:
/* ************************************************************************** */

const char* AForm::GradeTooHighException::what() const throw()
{
	return ("The grade is too high!");
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return ("The grade is too low!");
}

const char* AForm::UnsignedFormException::what() const throw()
{
	return ("The form is not signed!");
}

void	AForm::checkGrade(void)
{
	try
	{
		if (this->getReqGradeForSign() < MAX_GRADE)
			throw GradeTooHighException();
		else if (this->getReqGradeForSign() > MIN_GRADE)
			throw GradeTooLowException();
		if (this->getReqGradeForExec() < MAX_GRADE)
			throw GradeTooHighException();
		else if (this->getReqGradeForExec() > MIN_GRADE)
			throw GradeTooLowException();
	}
	catch (const GradeTooHighException& e)
	{
		std::cout << "\033[0;31m" << "Error: " << e.what() << "\033[0;39m" << std::endl;
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

// Stream operator overload to print AForm Class instances:
/* ************************************************************************** */

std::ostream&	operator<<(std::ostream& os, const AForm& obj)
{
	const AForm*	ptr;

	ptr = &obj;
	if (ptr == NULL)
		os << "Not a valid Form";
	else
	{
		os << "AForm "<< obj.getName() << " (signed [";
		if (obj.getSignatureStatus())
			os << "yes";
		else
			os << "no";
		os << "] - reqSign: " << obj.getReqGradeForSign() << " - reqExec: "
			<< obj.getReqGradeForExec() << ")";
	}
	return (os);
}
