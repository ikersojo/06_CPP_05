#include "../inc/PresidentialPardonForm.hpp"

// Constructors:
/* ************************************************************************** */

PresidentialPardonForm::PresidentialPardonForm(void) : AForm("PresidentialPardonForm", 25, 5)
{
	if (DEBUG == 1)
		std::cout << "\033[0;93m" << "Default PresidentialPardonForm Constructor called (" << this->getName()
					<< ")." << "\033[0;39m" << std::endl;
	this->_target = "undefined target";
}

PresidentialPardonForm::PresidentialPardonForm(const std::string target) : AForm("PresidentialPardonForm", 25, 5)
{
	if (DEBUG == 1)
		std::cout << "\033[0;93m" << "Named PresidentialPardonForm Constructor called (" << this->getName()
					<< ")." << "\033[0;39m" << std::endl;
	this->_target = target;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& obj) :
	AForm(obj.getName(), obj.getReqGradeForSign(), obj.getReqGradeForExec()) // duda
{
	if (DEBUG == 1)
		std::cout << "\033[0;93m" << "Copy PresidentialPardonForm Constructor called (" << obj.getName()
					<< ")." << "\033[0;39m" << std::endl;
	*this = obj;
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
		this->_signed = rhs.getSignatureStatus(); // modificar definicion de AForm para incluir el status de la signature para poder copiarlo? como lo firmo?
	}
	return (*this);
}

// Member functions:
/* ************************************************************************** */

std::string	PresidentialPardonForm::getTarget(void) const
{
	return (this->_target);
}

void	execute(Bureaucrat const & executor) const
{

}
