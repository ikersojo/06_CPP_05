/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isojo-go <isojo-go@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 20:56:17 by isojo-go          #+#    #+#             */
/*   Updated: 2023/06/13 08:20:17 by isojo-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_HPP
	#define MAIN_HPP
	#ifndef DEBUG
		#define DEBUG 0
	#endif

	#include <string>
	#include <iostream>
	#include "../classes/inc/Bureaucrat.hpp"
	#include "../classes/inc/PresidentialPardonForm.hpp"
	#include "../classes/inc/RobotomyRequestForm.hpp"
	#include "../classes/inc/ShrubberyCreationForm.hpp"
	#include "../classes/inc/AForm.hpp"
	#include "../classes/inc/Intern.hpp"

	int		test1(void);
	void	printBlueLine(std::string str);
	void	printRedLine(std::string str);

#endif // MAIN_HPP
