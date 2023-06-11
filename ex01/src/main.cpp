/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isojo-go <isojo-go@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 20:56:13 by isojo-go          #+#    #+#             */
/*   Updated: 2023/06/11 12:42:07 by isojo-go         ###   ########.fr       */
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
	Form	f1("papeleo1", 3, 5);
	Form	f2;
	Form	f3 = f1;
	Form	f4(f1);

	printBlueLine("-------------------- pointer to Form -------------------------");
	Form*	ptr_f;
	ptr_f = new Form("directiva2", 23, 48);

	printBlueLine("------------------ out of range construction check ---------------------------");
	Form	f5("grande", 203, 12);
	Form	f6("pequeño", 0, 12);
	Form	f7("grande2", 1, 433);
	Form	f8("pequeño2", 1, 0);
	std::cout << f5 << std::endl;
	std::cout << f6 << std::endl;
	std::cout << f7 << std::endl;
	std::cout << f8 << std::endl;

	printBlueLine("--------------------- signature check ------------------------");
	Bureaucrat b1("iker", 5);
	std::cout << b1 << std::endl;

	printBlueLine("------");
	std::cout << f1 << std::endl;
	b1.signForm(f1);
	std::cout << f1 << std::endl;

	printBlueLine("------");
	std::cout << f5 << std::endl;
	b1.signForm(f5);
	std::cout << f5 << std::endl;

	printBlueLine("------");
	std::cout << f7 << std::endl;
	b1.signForm(f7);
	std::cout << f7 << std::endl;

	printBlueLine("------------------ copy checks ---------------------------");
	printBlueLine("Copied instances maintaining intial values (deep copy):");
	std::cout << f3 << std::endl;
	std::cout << f4 << std::endl;

	printBlueLine("---------------------- delete pointer -----------------------");
	delete ptr_f;
	printBlueLine("------------------- end of main --------------------------");
	return (0);
}
