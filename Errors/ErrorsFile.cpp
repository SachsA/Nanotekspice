//
// EPITECH PROJECT, 2018
// Nano Tek Spice
// File description:
// ErrosFile Cpp
//

#include "ErrorsFile.hpp"

ErrorsFile::ErrorsFile(std::ostream &os, const std::string &message) throw()
	: Errors(os, message)
{}

ErrorsFile::~ErrorsFile(void) throw()
{}
