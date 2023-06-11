/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isojo-go <isojo-go@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 20:56:13 by isojo-go          #+#    #+#             */
/*   Updated: 2023/06/11 11:05:17 by isojo-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/main.hpp"

static void	printBlueLine(std::string str)
{
	std::cout  << std::endl << "\033[0;94m" << str
				<< "\033[0;39m" << std::endl;
}

int main(void)
{
	printBlueLine("-------------------- construction checks -------------------------");
	Bureaucrat	b1("iker", 3);
	Bureaucrat	b2;
	Bureaucrat	b3 = b1;
	Bureaucrat	b4(b1);

	printBlueLine("-------------------- pointer to Bureaucrat -------------------------");
	Bureaucrat*	ptr_b;
	ptr_b = new Bureaucrat("laura", 1);

	printBlueLine("------------------ out of range construction check ---------------------------");
	Bureaucrat	b5("pepe", 203);
	Bureaucrat	b6("popi", 0);
	std::cout << b5 << std::endl;
	std::cout << b6 << std::endl;

	printBlueLine("--------------------- increment check ------------------------");
	std::cout << b1 << std::endl;
	b1.incrementGrade();
	b1.incrementGrade();
	b1.incrementGrade();
	b1.incrementGrade();
	std::cout << b1 << std::endl;

	printBlueLine("--------------------- decrement check ------------------------");
	std::cout << b2 << std::endl;
	b2.decrementGrade();
	b2.decrementGrade();
	std::cout << b2 << std::endl;

	printBlueLine("---------------------- decrement / increment check on pointer -----------------------");
	std::cout << *ptr_b << std::endl;
	ptr_b->decrementGrade();
	ptr_b->decrementGrade();
	std::cout << *ptr_b << std::endl;
	ptr_b->incrementGrade();
	ptr_b->incrementGrade();
	ptr_b->incrementGrade();
	std::cout << *ptr_b << std::endl;

	printBlueLine("------------------ copy checks ---------------------------");
	printBlueLine("Copied instances maintaining intial values (deep copy):");
	std::cout << b3 << std::endl;
	std::cout << b4 << std::endl;

	printBlueLine("---------------------- delete pointer -----------------------");
	delete ptr_b;
	printBlueLine("------------------- end of main --------------------------");
	return (0);
}
