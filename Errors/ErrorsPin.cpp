//
// EPITECH PROJECT, 2018
// Nano Tek Spice
// File description:
// ErrosPin Cpp
//

#include "ErrorsPin.hpp"

ErrorsPin::ErrorsPin(std::ostream &os, const std::string &message) throw()
	: ErrorsChipset(os, message)
{}

ErrorsPin::~ErrorsPin(void) throw()
{}
