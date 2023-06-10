/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isojo-go <isojo-go@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 20:56:26 by isojo-go          #+#    #+#             */
/*   Updated: 2023/06/10 20:59:28 by isojo-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
	#define BUREAUCRAT_HPP

	#ifndef DEBUG
		#define DEBUG 0
	#endif

	#define MIN_GRADE 150
	#define MAX_GRADE 1

	#include <string>
	#include <iostream>
	#include <exception>

	class Bureaucrat
	{
		public:
			// Constructors:
			Bureaucrat(void);
			Bureaucrat(const std::string name, const int grade);
			Bureaucrat(const Bureaucrat& obj);

			// Destructor:
			~Bureaucrat(void);

			// Operator Override:
			Bureaucrat&	operator=(const Bureaucrat& rhs);

			// Member functions:
			const std::string&	getName(void) const;
			int					getGrade(void) const;
			void				incrementGrade(void);
			void				decrementGrade(void);

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
			int					_grade;
	};

	// Stream operator overload to print Bureaucrat Class instances:
	std::ostream&	operator<<(std::ostream& os, const Bureaucrat& obj);

#endif // BUREAUCRAT_HPP
