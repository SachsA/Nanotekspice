//
// EPITECH PROJECT, 2018
// Nano Tek Spice
// File description:
// Shell Cpp
//

#include <regex>
#include <csignal>
#include <algorithm>
#include <unistd.h>
#include "Shell.hpp"
#include "Input.hpp"
#include "ErrorsShell.hpp"
#include "ErrorsInput.hpp"

char Shell::_loop = 0;

void Shell::empty(int sig)
{
	(void)sig;
	Shell::_loop = 0;
}

void Shell::display(Circuit &circuit)
{
	circuit.display();
}

void Shell::dump(Circuit &circuit)
{
	circuit.dump();
	circuit.display();
}

void Shell::exit(Circuit &circuit)
{
	(void)circuit;
	_stop = 1;
}

void Shell::simulate(Circuit &circuit)
{
	circuit.simulate();
}

void Shell::loop(Circuit &circuit)
{
	Shell::_loop = 1;
	while (Shell::_loop == 1) {
		circuit.simulate();
#ifdef __BONUS__
		sleep(1);
		circuit.display();
		std::cout << std::endl;
#endif /* !__BONUS__ */
	}
	signal(SIGINT, empty);	
}

char Shell::equal_sep(char check_space)
{
	if (check_space == ' ')
		return 1;
	return 0;
}

std::string Shell::clean_str(std::string &str)
{
	int i = -1;
	int j = -1;
	int size = str.length();

	std::replace(str.begin(), str.end(), '\t', ' ');
	while (++i <= size) {
		j = -1;
		while (++j <= i) {
			if(equal_sep(str[j]) && equal_sep(str[j + 1]))
				str.erase(str.begin() + j);
			else if(equal_sep(str[0]))
				str.erase(str.begin());
			else if(str[j] == '\0' && equal_sep(str[j - 1]))
				str.erase(str.end() - 1);
		}
	}
	return str;
}

void Shell::check_cmd(std::string &str, Circuit &circuit)
{
	void (Shell::*fp)(Circuit &circuit);

	if (_exec.find(str) != _exec.end()) {
		fp = _exec[str];
		(this->*fp)(circuit);
	}
	else if (str.size() > 0)
		std::cout << "'" << str << "': unknown command" << std::endl;
}

void Shell::init_shell_and_cmd()
{
	_stop = 0;
	signal(SIGINT, Shell::empty);
	_exec.emplace("exit", &Shell::exit);
	_exec.emplace("simulate", &Shell::simulate);
	_exec.emplace("dump", &Shell::dump);
	_exec.emplace("display", &Shell::display);
	_exec.emplace("loop", &Shell::loop);
}

void Shell::set_input_value(std::string value, Input *input)
{
	if (value == "0")
		input->setValue(nts::Tristate::FALSE);
	else if (value == "1")
		input->setValue(nts::Tristate::TRUE);
	else
		std::cerr << "Error: The value of an input must be 0 or 1." << std::endl;
}

void Shell::create_link_shell(std::string const str, Circuit &circuit)
{
	Born born1;
	Born born2;
	std::smatch match;
	std::regex reg("^(\\S+):(\\d+)->(\\S+):(\\d+)");

	if (std::regex_search(str, match, reg)) {
		born1 = std::make_pair(match.str(1), stoi(match.str(2)));
		born2 = std::make_pair(match.str(3), stoi(match.str(4)));
		if (born1 == born2)
			std::cerr << "You can't link a born to itself." << std::endl;
		circuit.setLink(born1, born2);
	} else {
		std::cerr << "Bad syntax to set a link" << std::endl;
	}
}

void Shell::minish(Circuit &circuit)
{
	size_t set = 0;
	std::string name;
	std::string str;
	std::string value;
	Input *input;

	init_shell_and_cmd();
	simulate(circuit);
	display(circuit);
	while (_stop == 0) {
		std::cout << "> ";
		if (!std::getline(std::cin, str))
			exit(circuit);
		else
			str = clean_str(str);
		if ((set = str.find_first_of("=")) != std::string::npos) {
			value = str.substr(set + 1, str.size());
			name = str.substr(0, set);
			if ((input = dynamic_cast<Input *>(circuit[name])))	
				set_input_value(value, input);
			else
				std::cerr << "You can't change the value of an output" << std::endl;
		}
#ifdef __BONUS__
		else if ((set = str.find_first_of("->")) != std::string::npos)
			create_link_shell(str, circuit);
#endif /* !__BONUS__ */
		else
			check_cmd(str, circuit);
	}
}
