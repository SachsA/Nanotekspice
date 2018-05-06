//
// EPITECH PROJECT, 2018
// Nano Tek Spice
// File description:
// Shell Hpp
//

#ifndef SHELL_HPP_
	#define SHELL_HPP_

	#include <unordered_map>
	#include "Circuit.hpp"

	class Shell {
	public:
		Shell() = default;
		~Shell() = default;
		void minish(Circuit &circuit);
	private:
		using func = void (Shell::*)(Circuit &circuit);

		char _stop;
		static char _loop;
		std::unordered_map<std::string, func> _exec;
		static void empty(int sig);
		void create_link_shell(std::string const str, Circuit &circuit);
		void set_input_value(std::string value, Input *input);
		void check_cmd(std::string &str, Circuit &circuit);
		std::string clean_str(std::string &str);
		char equal_sep(char check);
		void init_shell_and_cmd();
		void loop(Circuit &circuit);
		void display(Circuit &circuit);
		void dump(Circuit &circuit);
		void simulate(Circuit &circuit);
		void exit(Circuit &circuit);
	};

#endif /* !SHELL_HPP_ */
