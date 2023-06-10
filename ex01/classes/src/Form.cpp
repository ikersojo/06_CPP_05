
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
		std::cout << "\033[0;93m" << "Nanmed Form Constructor called (" << this->getName()
					<< ")." << "\033[0;39m" << std::endl;
	if (Form::checkGradeOK(reqGradeForSign))
	{
		this->~Form();
	}
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
		std::cout << "\033[0;93m" << "Default Form Destructor called"
					<< "\033[0;39m" << std::endl;
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
		if (bureaucrat.getGrade() >= this->getReqGradeForSign())
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

bool	Form::checkGradeOK(int grade)
{
	try
	{
		if (grade < MAX_GRADE)
			throw GradeTooHighException();
		else if (grade > MIN_GRADE)
			throw GradeTooLowException();
		else
			return (true);
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
	return (false);
}

// Stream operator overload to print Form Class instances:
/* ************************************************************************** */

std::ostream&	operator<<(std::ostream& os, const Form& obj)
{
	os << obj.getName() << " (Form grade " << obj.getReqGradeForSign() << ")";
	return (os);
}
