#include "../inc/main.hpp"

int	test1(void)
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
