/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isojo-go <isojo-go@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 20:56:13 by isojo-go          #+#    #+#             */
/*   Updated: 2023/06/12 23:11:26 by isojo-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/main.hpp"

static void	printBlueLine(std::string str)
{
	std::cout  << std::endl << "\033[0;94m" << str
				<< "\033[0;39m" << std::endl;
}

static void	printRedLine(std::string str)
{
	std::cout  << std::endl << "\033[0;31m" << str
				<< "\033[0;39m" << std::endl;
}

static int	test1(void)
{
	printBlueLine("-------------------- construction checks -------------------------");
	ShrubberyCreationForm	f1("target1");
	ShrubberyCreationForm	f2;
	ShrubberyCreationForm	f3 = f1;
	ShrubberyCreationForm	f4(f1);

	printBlueLine("-------------------- pointer to AForm -------------------------");
	ShrubberyCreationForm*	ptr_f;
	ptr_f = new ShrubberyCreationForm("ramon");

	printBlueLine("--------------------- signature check ------------------------");
	Bureaucrat b1("iker", 1);
	std::cout << b1 << std::endl;

	Bureaucrat b2("helene", 140);
	std::cout << b2 << std::endl;

	Bureaucrat b3("urko", 150);
	std::cout << b3 << std::endl;

	printBlueLine("------");
	std::cout << f1 << std::endl;
	b1.executeForm(f1);
	std::cout << f1 << std::endl;
	b1.signForm(f1);
	std::cout << f1 << std::endl;
	b1.executeForm(f1);

	printBlueLine("------");
	std::cout << f2 << std::endl;
	b2.executeForm(f2);
	std::cout << f2 << std::endl;
	b2.signForm(f2);
	std::cout << f2 << std::endl;
	b2.executeForm(f2);

	printBlueLine("------");
	std::cout << f3 << std::endl;
	b3.executeForm(f3);
	std::cout << f3 << std::endl;
	b3.signForm(f3);
	std::cout << f3 << std::endl;
	b3.executeForm(f3);

	printBlueLine("------------------ copy checks ---------------------------");
	printBlueLine("Copied instances maintaining intial values (deep copy):");
	std::cout << f4 << std::endl;

	printBlueLine("---------------------- delete pointer -----------------------");
	delete ptr_f;
	printBlueLine("------------------- end of function --------------------------");
	return (0);
}

static int	test2(void)
{
	printBlueLine("-------------------- construction checks -------------------------");
	RobotomyRequestForm	f1("target1");
	RobotomyRequestForm	f2;
	RobotomyRequestForm	f3 = f1;
	RobotomyRequestForm	f4(f1);

	printBlueLine("-------------------- pointer to AForm -------------------------");
	RobotomyRequestForm*	ptr_f;
	ptr_f = new RobotomyRequestForm("ramon");

	printBlueLine("--------------------- signature check ------------------------");
	Bureaucrat b1("iker", 1);
	std::cout << b1 << std::endl;

	Bureaucrat b2("helene", 100);
	std::cout << b2 << std::endl;

	Bureaucrat b3("urko", 50);
	std::cout << b3 << std::endl;

	printBlueLine("------");
	std::cout << f1 << std::endl;
	b1.executeForm(f1);
	std::cout << f1 << std::endl;
	b1.signForm(f1);
	std::cout << f1 << std::endl;
	printBlueLine("------");
	b1.executeForm(f1);
	printBlueLine("------");
	b1.executeForm(f1);
	printBlueLine("------");
	b1.executeForm(f1);
	printBlueLine("------");
	b1.executeForm(f1);
	printBlueLine("------");
	b1.executeForm(f1);
	printBlueLine("------");
	b1.executeForm(f1);

	printBlueLine("------");
	std::cout << f2 << std::endl;
	b2.executeForm(f2);
	std::cout << f2 << std::endl;
	b2.signForm(f2);
	std::cout << f2 << std::endl;
	b2.executeForm(f2);

	printBlueLine("------");
	std::cout << f3 << std::endl;
	b3.executeForm(f3);
	std::cout << f3 << std::endl;
	b3.signForm(f3);
	std::cout << f3 << std::endl;
	b3.executeForm(f3);

	printBlueLine("------------------ copy checks ---------------------------");
	printBlueLine("Copied instances maintaining intial values (deep copy):");
	std::cout << f4 << std::endl;

	printBlueLine("---------------------- delete pointer -----------------------");
	delete ptr_f;
	printBlueLine("------------------- end of function --------------------------");
	return (0);
}

static int	test3(void)
{
	printBlueLine("-------------------- construction checks -------------------------");
	PresidentialPardonForm	f1("target1");
	PresidentialPardonForm	f2;
	PresidentialPardonForm	f3 = f1;
	PresidentialPardonForm	f4(f1);

	printBlueLine("-------------------- pointer to AForm -------------------------");
	PresidentialPardonForm*	ptr_f;
	ptr_f = new PresidentialPardonForm("ramon");

	printBlueLine("--------------------- signature check ------------------------");
	Bureaucrat b1("iker", 1);
	std::cout << b1 << std::endl;

	Bureaucrat b2("helene", 100);
	std::cout << b2 << std::endl;

	Bureaucrat b3("urko", 20);
	std::cout << b3 << std::endl;

	printBlueLine("------");
	std::cout << f1 << std::endl;
	b1.executeForm(f1);
	std::cout << f1 << std::endl;
	b1.signForm(f1);
	std::cout << f1 << std::endl;
	b1.executeForm(f1);

	printBlueLine("------");
	std::cout << f2 << std::endl;
	b2.executeForm(f2);
	std::cout << f2 << std::endl;
	b2.signForm(f2);
	std::cout << f2 << std::endl;
	b2.executeForm(f2);

	printBlueLine("------");
	std::cout << f3 << std::endl;
	b3.executeForm(f3);
	std::cout << f3 << std::endl;
	b3.signForm(f3);
	std::cout << f3 << std::endl;
	b3.executeForm(f3);

	printBlueLine("------------------ copy checks ---------------------------");
	printBlueLine("Copied instances maintaining intial values (deep copy):");
	std::cout << f4 << std::endl;

	printBlueLine("---------------------- delete pointer -----------------------");
	delete ptr_f;
	printBlueLine("------------------- end of function --------------------------");
	return (0);
}

int main(void)
{
	printRedLine("------------------ TEST 1: ShrubberyCreationForm ---------------------------");
	test1();
	printRedLine("---------------------------- END OF TEST 1 ----------------------------------");
	printRedLine("------------------ TEST 2: RobotomyRequestForm ---------------------------");
	test2();
	printRedLine("---------------------------- END OF TEST 2 ----------------------------------");
	printRedLine("------------------ TEST 3: PresidentialPardonForm ---------------------------");
	test3();
	printRedLine("---------------------------- END OF TEST 3 ----------------------------------");
	return (0);
}
