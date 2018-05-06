//
// EPITECH PROJECT, 2018
// Nano Tek Spice
// File description:
// ErrosChipset Cpp
//

#include "ErrorsChipset.hpp"

ErrorsChipset::ErrorsChipset(std::ostream &os, const std::string &message) throw()
	: Errors(os, message)
{}

ErrorsChipset::~ErrorsChipset(void) throw()
{}
