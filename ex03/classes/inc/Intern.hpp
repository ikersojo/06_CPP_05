
#ifndef INTERN_HPP
	#define INTERN_HPP

	#include "../inc/AForm.hpp"
	#include "../inc/ShrubberyCreationForm.hpp"
	#include "../inc/RobotomyRequestForm.hpp"
	#include "../inc/PresidentialPardonForm.hpp"

	class AForm;

	class Intern
	{
		public:
			// Constructors:
			Intern(void);
			Intern(const Intern& obj);

			// Destructor:
			~Intern(void);

			// Operator Override:
			Intern&	operator=(const Intern& rhs);

			// Member functions:
			AForm*	makeForm(const std::string formName, const std::string target);

		private:
			// Exceptions:
			void	checkGrade(void);
			class NonValidFormException : public std::exception
			{
				public:
					virtual const char* what() const throw();
			};
	};

	// Stream operator overload to print Intern Class instances:
	std::ostream&	operator<<(std::ostream& os, const Intern& obj);

#endif // INTERN_HPP
