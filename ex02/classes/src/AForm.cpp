
#include "../inc/AForm.hpp"

// Constructors:
/* ************************************************************************** */

AForm::AForm(void) : _name("un-named"), _signed(false), _reqGradeForSign(MIN_GRADE), _reqGradeForExec(MIN_GRADE)
{
	if (DEBUG == 1)
		std::cout << "\033[0;93m" << "Default AForm Constructor called (" << this->getName()
					<< ")." << "\033[0;39m" << std::endl;
}

AForm::AForm(const std::string name, const int reqGradeForSign, const int reqGradeForExec) :
			_name(name), _signed(false), _reqGradeForSign(reqGradeForSign), _reqGradeForExec(reqGradeForExec)
{
	if (DEBUG == 1)
		std::cout << "\033[0;93m" << "Named AForm Constructor called (" << this->getName()
					<< ")." << "\033[0;39m" << std::endl;
	AForm::checkGrade();
}

AForm::AForm(const AForm& obj) : _name(obj.getName()), _signed(false), _reqGradeForSign(obj.getReqGradeForSign()),
								_reqGradeForExec(obj.getReqGradeForExec())
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
		this->~AForm();
		new(this) AForm(rhs.getName(), rhs.getReqGradeForSign(), rhs.getReqGradeForExec());
		this->_signed = rhs.getSignatureStatus();
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
	return (this->_signed);
}

int	AForm::getReqGradeForSign(void) const
{
	return (this->_reqGradeForSign);
}

int	AForm::getReqGradeForExec(void) const
{
	return (this->_reqGradeForExec);
}

void	AForm::beSigned(const Bureaucrat& bureaucrat)
{
	if (this->getSignatureStatus() == false)
	{
		if (bureaucrat.getGrade() <= this->getReqGradeForSign())
		{
			this->_signed = true;
		}
	}
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

void	AForm::checkGrade(void)
{
	std::string	tempName = this->getName();
	bool		tempSignedStatus = this->getSignatureStatus();
	int			tempGradeSign = this->getReqGradeForSign();
	int			tempGradeExec = this->getReqGradeForExec();

	try
	{
		if (this->getReqGradeForSign() < MAX_GRADE)
		{
			this->~AForm();
			new(this) AForm(tempName, 1, tempGradeExec);
			this->_signed = tempSignedStatus;
			throw GradeTooHighException();
		}
		else if (this->getReqGradeForSign() > MIN_GRADE)
		{
			this->~AForm();
			new(this) AForm(tempName, 150, tempGradeExec);
			this->_signed = tempSignedStatus;
			throw GradeTooLowException();
		}
		if (this->getReqGradeForExec() < MAX_GRADE)
		{
			this->~AForm();
			new(this) AForm(tempName, tempGradeSign, 1);
			this->_signed = tempSignedStatus;
			throw GradeTooHighException();
		}
		else if (this->getReqGradeForExec() > MIN_GRADE)
		{
			this->~AForm();
			new(this) AForm(tempName, tempGradeSign, 150);
			this->_signed = tempSignedStatus;
			throw GradeTooLowException();
		}
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
	os << "AForm "<< obj.getName() << " (signed [";
	if (obj.getSignatureStatus())
		os << "yes";
	else
		os << "no";
	os << "] - reqSign: " << obj.getReqGradeForSign() << " - reqExec: "
		<< obj.getReqGradeForExec() << ")";
	return (os);
}
