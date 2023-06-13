/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isojo-go <isojo-go@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 22:53:31 by isojo-go          #+#    #+#             */
/*   Updated: 2023/06/12 23:10:13 by isojo-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
	#define SHRUBBERYCREATIONFORM_HPP

	#include "../inc/AForm.hpp"
	#include <fstream>

	class ShrubberyCreationForm : public AForm
	{
		public:
			// Constructors:
			ShrubberyCreationForm(void);
			ShrubberyCreationForm(const std::string target);
			ShrubberyCreationForm(const ShrubberyCreationForm &obj);

			// Destructor:
			~ShrubberyCreationForm(void);

			// Operator Override:
			ShrubberyCreationForm &operator=(const ShrubberyCreationForm &rhs);

			// Member functions:
			void		execute(Bureaucrat const & executor) const;
			std::string	getTarget(void) const;

		private:
			// Attributes:
			std::string	_target;
	};

#endif // SHRUBBERYCREATIONFORM_HPP
