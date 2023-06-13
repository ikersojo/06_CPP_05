/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isojo-go <isojo-go@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 20:56:13 by isojo-go          #+#    #+#             */
/*   Updated: 2023/06/13 08:11:31 by isojo-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/main.hpp"

void	printBlueLine(std::string str)
{
	std::cout  << std::endl << "\033[0;94m" << str
				<< "\033[0;39m" << std::endl;
}

void	printRedLine(std::string str)
{
	std::cout  << std::endl << "\033[0;31m" << str
				<< "\033[0;39m" << std::endl;
}

int main(void)
{
	printRedLine("------------------ TEST 1: Intern ---------------------------");
	test1();
	printRedLine("------------------- END OF TEST 1 ---------------------------");
	return (0);
}
