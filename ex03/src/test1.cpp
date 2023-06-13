#include "../inc/main.hpp"

int	test1(void)
{
	printBlueLine("-------------------- MANDATORY -------------------------");
	Intern	someRandomIntern;
	AForm*	rrf;
	AForm*	scf;
	AForm*	ppf;
	AForm*	other;

	printBlueLine("------");
	rrf = someRandomIntern.makeForm("robotomy request", "Bender");
	scf = someRandomIntern.makeForm("shrubbery creation", "Bender");
	ppf = someRandomIntern.makeForm("presidential pardon", "Bender");
	other = someRandomIntern.makeForm("other", "Bender");
	printBlueLine("------");
	std::cout << *rrf << std::endl;
	std::cout << *scf << std::endl;
	std::cout << *ppf << std::endl;
	std::cout << *other << std::endl;

	printBlueLine("--------------------- signature check ------------------------");
	Bureaucrat b1("iker", 1);
	std::cout << b1 << std::endl;

	printBlueLine("------");
	std::cout << *rrf << std::endl;
	b1.executeForm(*rrf);
	std::cout << *rrf << std::endl;
	b1.signForm(*rrf);
	std::cout << *rrf << std::endl;
	b1.executeForm(*rrf);

	printBlueLine("------");
	std::cout << *scf << std::endl;
	b1.executeForm(*scf);
	std::cout << *scf << std::endl;
	b1.signForm(*scf);
	std::cout << *scf << std::endl;
	b1.executeForm(*scf);

	printBlueLine("------");
	std::cout << *ppf << std::endl;
	b1.executeForm(*ppf);
	std::cout << *ppf << std::endl;
	b1.signForm(*ppf);
	std::cout << *ppf << std::endl;
	b1.executeForm(*ppf);

	printBlueLine("------");
	std::cout << *other << std::endl;
	b1.executeForm(*other);
	std::cout << *other << std::endl;
	b1.signForm(*other);
	std::cout << *other << std::endl;
	b1.executeForm(*other);

	printBlueLine("------------------- delete form --------------------------");
	delete rrf;
	delete scf;
	delete ppf;
	delete other;

	printBlueLine("------------------- end of function --------------------------");
	return (0);
}
