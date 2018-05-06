//
// EPITECH PROJECT, 2018
// Nano Tek Spice
// File description:
// Errors Cpp
//

#include "Errors.hpp"

Errors::Errors(std::ostream &os, const std::string &message) throw()
	: _os(os)
{
	_message = message;
}

Errors::~Errors(void) throw()
{}

const char *Errors::what(void) const throw()
{
	return _message.c_str();
}
