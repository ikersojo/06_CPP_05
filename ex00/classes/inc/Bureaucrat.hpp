#ifndef BUREAUCRAT_HPP
	#define BUREAUCRAT_HPP
	#ifndef DEBUG
		#define DEBUG 0
	#endif

	#include <string>
	#include <iostream>

	class Bureaucrat
	{
		public:
			Bureaucrat(void);
			Bureaucrat(const std::string name, const int grade);
			Bureaucrat(const Bureaucrat& obj);
			~Bureaucrat(void);

			Bureaucrat&	operator=(const Bureaucrat& rhs);

			const std::string&	getName(void) const;
			const int			getGrade(void) const;
			void				incrementGrade(void);
			void				decrementGrade(void);
		private:
			const std::string	_name;
			int					_grade;
	};


	std::ostream&	operator<<(std::ostream& os, const Bureaucrat& obj);

#endif // BUREAUCRAT_HPP
