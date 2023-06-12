/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isojo-go <isojo-go@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 18:53:29 by isojo-go          #+#    #+#             */
/*   Updated: 2023/06/12 20:01:36 by isojo-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
			AForm(const std::string name, bool signedStatus, const int reqGradeForSign, const int reqGradeForExec);
			AForm(const AForm& obj);

			// Destructor:
			virtual ~AForm(void) = 0;

			// Operator Override:
			virtual AForm&	operator=(const AForm& rhs);

			// Member functions:
			const std::string&	getName(void) const;
			bool				getSignatureStatus(void) const;
			void				setSignatureStatus(bool status);
			int					getReqGradeForSign(void) const;
			int					getReqGradeForExec(void) const;
			void				beSigned(const Bureaucrat& bureaucrat);
			virtual void		execute(Bureaucrat const & executor) const = 0;
			bool				checkExecute(Bureaucrat const & executor) const;

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

			class UnsignedFormException : public std::exception
			{
				public:
					virtual const char* what() const throw();
			};

			// Attributes:
			const std::string	_name;
			bool				_signedStatus;
			const int			_reqGradeForSign;
			const int			_reqGradeForExec;
	};

	// Stream operator overload to print AForm Class instances:
	std::ostream&	operator<<(std::ostream& os, const AForm& obj);

#endif // AFORM_HPP
