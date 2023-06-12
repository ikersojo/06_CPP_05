/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isojo-go <isojo-go@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 18:53:36 by isojo-go          #+#    #+#             */
/*   Updated: 2023/06/12 22:38:09 by isojo-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
	#define PRESIDENTIALPARDONFORM_HPP

	#include "../inc/AForm.hpp"

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
