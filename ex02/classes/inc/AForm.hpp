
#ifndef AFORM_HPP
	#define AFORM_HPP

	#ifndef DEBUG
		#define DEBUG 0
	#endif

	#include <string>
	#include <iostream>
	#include <exception>
	#include "../inc/Bureaucrat.hpp"

	class Bureaucrat;

	class AForm
	{
		public:
			// Constructors:
			AForm(void);
			AForm(const std::string name, const int reqGradeForSign, const int reqGradeForExec);
			AForm(const AForm& obj);

			// Destructor:
			virtual ~AForm(void) = 0;

			// Operator Override:
			AForm&	operator=(const AForm& rhs);

			// Member functions:
			const std::string&	getName(void) const;
			bool				getSignatureStatus(void) const;
			int					getReqGradeForSign(void) const;
			int					getReqGradeForExec(void) const;
			void				beSigned(const Bureaucrat& bureaucrat);

		private:
			// Exceptions:
			void	checkGrade(void);
			class GradeTooHighException : public std::exception
			{
				public:
					virtual const char* what() const throw();
			};

			class GradeTooLowException : public std::exception
			{
				public:
					virtual const char* what() const throw();
			};

			// Attributes:
			const std::string	_name;
			bool				_signed;
			const int			_reqGradeForSign;
			const int			_reqGradeForExec;
	};

	// Stream operator overload to print AForm Class instances:
	std::ostream&	operator<<(std::ostream& os, const AForm& obj);

#endif // AFORM_HPP
