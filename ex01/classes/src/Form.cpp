
#include "../inc/Form.hpp"

// Constructors:
/* ************************************************************************** */

Form::Form(void) : _name("un-named"), _signed(false), _reqGradeForSign(MIN_GRADE), _reqGradeForExec(MIN_GRADE)
{
	if (DEBUG == 1)
		std::cout << "\033[0;93m" << "Default Form Constructor called (" << this->getName()
					<< ")." << "\033[0;39m" << std::endl;
}

Form::Form(const std::string name, const int reqGradeForSign, const int reqGradeForExec) :
			_name(name), _signed(false), _reqGradeForSign(reqGradeForSign), _reqGradeForExec(reqGradeForExec)
{
	if (DEBUG == 1)
		std::cout << "\033[0;93m" << "Named Form Constructor called (" << this->getName()
					<< ")." << "\033[0;39m" << std::endl;
	Form::checkGrade();
}

Form::Form(const Form& obj) : _name(obj.getName()), _signed(false), _reqGradeForSign(obj.getReqGradeForSign()),
								_reqGradeForExec(obj.getReqGradeForExec())
{
	if (DEBUG == 1)
		std::cout << "\033[0;93m" << "Copy Form Constructor called (" << obj.getName()
					<< ")." << "\033[0;39m" << std::endl;
	*this = obj;
}

// Destructor:
/* ************************************************************************** */

Form::~Form(void)
{
	if (DEBUG == 1)
		std::cout << "\033[0;93m" << "Default Form Destructor called (" << this->getName()
					<< ")." << "\033[0;39m" << std::endl;
}

// Operator Override:
/* ************************************************************************** */

Form&	Form::operator=(const Form& rhs)
{
	if (this != &rhs)
	{
		this->~Form();
		new(this) Form(rhs.getName(), rhs.getReqGradeForSign(), rhs.getReqGradeForExec());
		this->_signed = rhs.getSignatureStatus();
	}
	return (*this);
}

// Member functions:
/* ************************************************************************** */

const std::string&	Form::getName(void) const
{
	return (this->_name);
}

bool	Form::getSignatureStatus(void) const
{
	return (this->_signed);
}

int	Form::getReqGradeForSign(void) const
{
	return (this->_reqGradeForSign);
}

int	Form::getReqGradeForExec(void) const
{
	return (this->_reqGradeForExec);
}

void	Form::beSigned(const Bureaucrat& bureaucrat)
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

const char* Form::GradeTooHighException::what() const throw()
{
	return ("The grade is too high!");
}

const char* Form::GradeTooLowException::what() const throw()
{
	return ("The grade is too low!");
}

void	Form::checkGrade(void)
{
	std::string	tempName = this->getName();
	bool		tempSignedStatus = this->getSignatureStatus();
	int			tempGradeSign = this->getReqGradeForSign();
	int			tempGradeExec = this->getReqGradeForExec();

	try
	{
		if (this->getReqGradeForSign() < MAX_GRADE)
		{
			this->~Form();
			new(this) Form(tempName, 1, tempGradeExec);
			this->_signed = tempSignedStatus;
			throw GradeTooHighException();
		}
		else if (this->getReqGradeForSign() > MIN_GRADE)
		{
			this->~Form();
			new(this) Form(tempName, 150, tempGradeExec);
			this->_signed = tempSignedStatus;
			throw GradeTooLowException();
		}
		if (this->getReqGradeForExec() < MAX_GRADE)
		{
			this->~Form();
			new(this) Form(tempName, tempGradeSign, 1);
			this->_signed = tempSignedStatus;
			throw GradeTooHighException();
		}
		else if (this->getReqGradeForExec() > MIN_GRADE)
		{
			this->~Form();
			new(this) Form(tempName, tempGradeSign, 150);
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

// Stream operator overload to print Form Class instances:
/* ************************************************************************** */

std::ostream&	operator<<(std::ostream& os, const Form& obj)
{
	os << "Form "<< obj.getName() << " (signed [";
	if (obj.getSignatureStatus())
		os << "yes";
	else
		os << "no";
	os << "] - reqSign: " << obj.getReqGradeForSign() << " - reqExec: "
		<< obj.getReqGradeForExec() << ")";
	return (os);
}
