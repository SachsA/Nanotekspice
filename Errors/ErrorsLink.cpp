//
// EPITECH PROJECT, 2018
// Nano Tek Spice
// File description:
// ErrosLink Cpp
//

#include "ErrorsLink.hpp"

ErrorsLink::ErrorsLink(std::ostream &os, const std::string &message) throw()
	: Errors(os, message)
{}

ErrorsLink::~ErrorsLink(void) throw()
{}
