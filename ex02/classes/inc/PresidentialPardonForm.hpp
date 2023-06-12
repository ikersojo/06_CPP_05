#ifndef PRESIDENTIALPARDONFORM_HPP
	#define PRESIDENTIALPARDONFORM_HPP

	#ifndef DEBUG
		#define DEBUG 0
	#endif

	#include <string>
	#include <iostream>
	#include <exception>
	#include "../inc/AForm.hpp"

	class Bureaucrat;

	class PresidentialPardonForm : public AForm
	{
		public:
			// Constructors:
			PresidentialPardonForm(void);
			PresidentialPardonForm(const std::string target);
			PresidentialPardonForm(const PresidentialPardonForm &obj);

			// Destructor:
			~PresidentialPardonForm(void);

			// Operator Override:
			PresidentialPardonForm &operator=(const PresidentialPardonForm &rhs);

			// Member functions:
			void		execute(Bureaucrat const & executor) const;
			std::string	getTarget(void) const;

		private:
			// Attributes:
			std::string	_target;
	};

#endif // PRESIDENTIALPARDONFORM_HPP
