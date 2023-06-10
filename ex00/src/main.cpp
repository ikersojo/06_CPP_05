#include "../inc/main.hpp"

static void	printBlueLine(std::string str)
{
	std::cout  << std::endl << "\033[0;94m" << str
				<< "\033[0;39m" << std::endl;
}

int main(void)
{
	printBlueLine("---------------------------------------------");
	Bureaucrat	b1("iker", 3);
	Bureaucrat	b2;
	Bureaucrat	b3 = b1;
	Bureaucrat	b4(b1);
	printBlueLine("---------------------------------------------");
	Bureaucrat*	ptr_b;
	ptr_b = new Bureaucrat("laura", 1);
	printBlueLine("---------------------------------------------");

	std::cout << b1 << std::endl;
	b1.incrementGrade();
	b1.incrementGrade();
	b1.incrementGrade();
	b1.incrementGrade();
	std::cout << b1 << std::endl;

	printBlueLine("---------------------------------------------");

	std::cout << b2 << std::endl;
	b2.decrementGrade();
	b2.decrementGrade();
	std::cout << b2 << std::endl;

	printBlueLine("---------------------------------------------");

	std::cout << *ptr_b << std::endl;
	ptr_b->decrementGrade();
	ptr_b->decrementGrade();
	std::cout << *ptr_b << std::endl;
	ptr_b->incrementGrade();
	ptr_b->incrementGrade();
	ptr_b->incrementGrade();
	std::cout << *ptr_b << std::endl;

	printBlueLine("---------------------------------------------");
	printBlueLine("Copied instances maintaining intial values (deep copy):");
	std::cout << b3 << std::endl;
	std::cout << b4 << std::endl;

	printBlueLine("---------------------------------------------");
	delete ptr_b;
	printBlueLine("---------------------------------------------");
	return (0);
}
