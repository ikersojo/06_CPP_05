/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isojo-go <isojo-go@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 22:38:20 by isojo-go          #+#    #+#             */
/*   Updated: 2023/06/12 22:38:32 by isojo-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
	#define ROBOTOMYREQUESTFORM_HPP

	#include <cstdlib>
	#include "../inc/AForm.hpp"

	class RobotomyRequestForm : public AForm
	{
		public:
			// Constructors:
			RobotomyRequestForm(void);
			RobotomyRequestForm(const std::string target);
			RobotomyRequestForm(const RobotomyRequestForm &obj);

			// Destructor:
			~RobotomyRequestForm(void);

			// Operator Override:
			RobotomyRequestForm &operator=(const RobotomyRequestForm &rhs);

			// Member functions:
			void		execute(Bureaucrat const & executor) const;
			std::string	getTarget(void) const;

		private:
			// Attributes:
			std::string	_target;
	};

#endif // ROBOTOMYREQUESTFORM_HPP
