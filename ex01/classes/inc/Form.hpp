/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isojo-go <isojo-go@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 18:51:46 by isojo-go          #+#    #+#             */
/*   Updated: 2023/06/12 18:51:49 by isojo-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
	#define FORM_HPP

	#ifndef DEBUG
		#define DEBUG 0
	#endif

	#include <string>
	#include <iostream>
	#include <exception>
	#include "../inc/Bureaucrat.hpp"

	class Bureaucrat;

	class Form
	{
		public:
			// Constructors:
			Form(void);
			Form(const std::string name, const int reqGradeForSign, const int reqGradeForExec);
			Form(const Form& obj);

			// Destructor:
			~Form(void);

			// Operator Override:
			Form&	operator=(const Form& rhs);

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

	// Stream operator overload to print Form Class instances:
	std::ostream&	operator<<(std::ostream& os, const Form& obj);

#endif // FORM_HPP
