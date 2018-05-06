//
// EPITECH PROJECT, 2018
// Nano Tek Spice
// File description:
// ErrosOutput Cpp
//

#include "ErrorsOutput.hpp"

ErrorsOutput::ErrorsOutput(std::ostream &os, const std::string &message) throw()
	: ErrorsLink(os, message)
{}

ErrorsOutput::~ErrorsOutput(void) throw()
{}
