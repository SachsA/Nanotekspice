//
// EPITECH PROJECT, 2018
// Nano Tek Spice
// File description:
// ErrosShell Cpp
//

#include "ErrorsShell.hpp"

ErrorsShell::ErrorsShell(std::ostream &os, const std::string &message) throw()
	: Errors(os, message)
{}

ErrorsShell::~ErrorsShell(void) throw()
{}
