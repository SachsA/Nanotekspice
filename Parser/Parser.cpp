//
// EPITECH PROJECT, 2018
// Nano Tek Spice
// File description:
// Parser Cpp
//

#include <iostream>
#include <sstream>
#include <fstream>
#include <regex>
#include <string>
#include "Input.hpp"
#include "Parser.hpp"
#include "ErrorsChipset.hpp"
#include "ErrorsInput.hpp"
#include "ErrorsLink.hpp"
#include "ErrorsFile.hpp"

std::ifstream Parser::authorized_file(const char *file)
{
	std::string ext;
	std::string str(file);
	std::ifstream fileName(file);

	if (!fileName)
		throw ErrorsFile(std::cerr, "'" + str + "': file not found.");
	ext = str.substr(str.find_last_of(".") + 1);
	if(ext != "nts")
		throw ErrorsFile(std::cerr, "'" + ext +
				 "': bad file's extension.");
	return fileName;
}

bool Parser::is_empty(std::string &line)
{
	size_t i = -1;

	while (++i < line.size())
		if (line[i] != '\t' && line[i] != ' ')
			return false;
	return true;
}

void Parser::epur(std::ifstream &fileName,
		  std::string &line,
		  std::stringstream &str)
{
	std::regex reg("^([^#]+)");
	std::smatch match;

	while (std::getline(fileName, line)) {
		if (std::regex_search(line, match, reg)) {
			line = match.str(1);
			if (is_empty(line) == false)
				str << line << std::endl;
		}
	}
}

void Parser::create_links(std::stringstream &str, Circuit &circuit)
{
	Born born1;
	Born born2;
	std::string compo;
	std::regex reg("^(\\S+):(\\d+)\\s+(\\S+):(\\d+)");
	std::smatch match;

	while (getline(str, compo)) {
		if (std::regex_search(compo, match, reg)) {
			born1 = std::make_pair(match.str(1), stoi(match.str(2)));
			born2 = std::make_pair(match.str(3), stoi(match.str(4)));
			if (born1 == born2)
				throw ErrorsLink(std::cerr, "You can't link a born to itself.");
			circuit.setLink(born1, born2);
		} else {
			throw ErrorsFile(std::cerr, "Bad Syntax in the file to set a link.");
		}
	}
}

void Parser::create_compo(std::stringstream &str, Circuit &circuit)
{
	std::string compo;
	std::regex reg("^(\\S+)\\s+([^\\s(]+)(?:\\(([^\\s]+)\\))?$");
	std::smatch match;

	while (getline(str, compo) && compo.find(".links:")) {
		if (std::regex_search(compo, match, reg))
			circuit.addComponent(match.str(1), match.str(2));
		else
			throw ErrorsChipset(std::cerr, "File's syntax is not good.");
	}
	if (compo.find(".links:"))
		throw ErrorsLink(std::cerr,
				 "There is no part '.links:' in the file.");
	create_links(str, circuit);
}

void Parser::parse(const char *file, Circuit &circuit)
{
	std::ifstream fileName;
	std::string line;
	std::stringstream str;

	fileName = authorized_file(file);
	epur(fileName, line, str);
	std::getline(str, line);
	if (!line.find(".chipsets:"))
		return create_compo(str, circuit);
	else
		throw ErrorsChipset(std::cerr,
				    "There is no part '.links:' in the file.");
}

void Parser::set_input_value(std::string value, Input *input)
{
	if (value == "0")
		input->setValue(nts::Tristate::FALSE, true);
	else if (value == "1")
		input->setValue(nts::Tristate::TRUE, true);
	else
		throw ErrorsInput(std::cerr, value + ": wrong value."
				  " Inputs are 0 or 1.");
}

void Parser::parse_args(int const argc, char const * const * const argv, Circuit &circuit)
{
	size_t nb;
	int i = 2;
	std::string name;
	std::string str;
	std::string value;
	Input *input;

	while (i < argc) {
		str = std::string(argv[i]);
		nb = str.find_first_of("=");
		if (nb != std::string::npos) {
			value = str.substr(nb + 1, str.size());
			name = str.substr(0, nb);
			input = static_cast<Input *>(circuit[name]);
			set_input_value(value, input);
		}
		i++;
	}
}
