//
// EPITECH PROJECT, 2018
// Nano
// File description:
// Main file
//

#include "Errors.hpp"
#include "Parser.hpp"
#include "Shell.hpp"
#include "Deep.hpp"

int Deep::compt = 0;

static int start(int argc, char **argv)
{
	Shell shell;
	Parser parser;
	Circuit circuit;
	int	ret = 84;

	try {
		parser.parse(argv[1], circuit);
		parser.parse_args(argc, argv, circuit);
		shell.minish(circuit);
		ret = 0;
	}
	catch (const Errors &e) {
		std::cout << "Error(s): " << e.what() << std::endl;
		ret = 84;
	}
	catch (...) {}
	return ret;
}

int main(int argc, char **argv)
{
	Shell shell;
	Parser parser;
	Circuit circuit;
	int	ret = 0;

	if (argc < 2)
		ret = 84;
	else
		ret = start(argc, argv);
	return ret;
}
