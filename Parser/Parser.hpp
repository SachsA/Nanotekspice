//
// EPITECH PROJECT, 2018
// Nano Tek Spice
// File description:
// Parser Hpp
//

#ifndef PARSER_HPP_
	#define PARSER_HPP_

	#include "Circuit.hpp"

	class Parser {
	public:
		Parser() = default;
		~Parser() = default;
		void parse_args(int const argc,
				char const * const * const argv,
				Circuit &circuit);
		void parse(const char *file, Circuit &circuit);
		bool is_empty(std::string &line);
		std::ifstream authorized_file(const char *file);
		void epur(std::ifstream &fileName,
			  std::string &line,
			  std::stringstream &str);
		void create_compo(std::stringstream &str, Circuit &circuit);
		void create_links(std::stringstream &str, Circuit &circuit);
		void set_input_value(std::string value, Input *input);
	};

#endif /* !PARSER_HPP_ */
