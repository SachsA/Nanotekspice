//
// EPITECH PROJECT, 2018
// Nano
// File description:
// Main tester
//

#include <string>
#include "Tester.hpp"
#include "Gates.hpp"

int main(int ac, char **av) {
	Gates	gateTester;
	int	verbose;
	size_t	fail = 0;

	if (ac > 1)
		verbose = stoi(std::string(av[1]));
	gateTester.setVerbose(verbose);
	fail += gateTester.gatesFull();
	if (fail)
		printf("\e[31mResult: \e[91m%li \e[31mtests failed", fail);
	else
		printf("\e[32mResult: All tests succeeded!");
	printf("\e[0m\n");
	return 0;
}