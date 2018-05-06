//
// EPITECH PROJECT, 2018
// Nano Tek Spice
// File description:
// ErrosInput Cpp
//

#include "ErrorsInput.hpp"

ErrorsInput::ErrorsInput(std::ostream &os, const std::string &message) throw()
	: Errors(os, message)
{}

ErrorsInput::~ErrorsInput(void) throw()
{}
