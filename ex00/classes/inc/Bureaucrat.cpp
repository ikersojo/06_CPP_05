#include "../inc/Bureaucrat.hpp"
// Bureaucrat::GradeTooHighException or a Bureaucrat::GradeTooLowException

Bureaucrat::Bureaucrat(void)
{

}

Bureaucrat::Bureaucrat(const std::string name, const int grade)
{

}

Bureaucrat::Bureaucrat(const Bureaucrat& obj)
{

}

Bureaucrat::~Bureaucrat(void)
{
	if (DEBUG == 1)
		std::cout << "\033[0;93m" << "Default Destructor called (" << this->getName()
					<< ")." << "\033[0;39m" << std::endl;
}

Bureaucrat&	Bureaucrat::operator=(const Bureaucrat& rhs)
{
	if (this != &rhs)
	{
		this->~Bureaucrat();
		new(this) Bureaucrat(rhs.getName(), rhs.getGrade());
	}
	return (*this);
}

const std::string&	Bureaucrat::getName(void) const
{
	return (this->_name);
}

const int	Bureaucrat::getGrade(void) const
{
	return (this->_grade);
}

void	Bureaucrat::incrementGrade(void)
{
	this->_grade--;
}

void	Bureaucrat::decrementGrade(void)
{
	this->_grade++;
}

std::ostream&	operator<<(std::ostream& os, const Bureaucrat& obj)
{
	os << obj.getName() << ", bureaucrat grade " << obj.getGrade() << "." << std::endl;
}
