//
// EPITECH PROJECT, 2018
// Nano Tek Spice
// File description:
// Errors Shell Hpp
//

#ifndef ERRORS_SHELL_HPP_
	#define ERRORS_SHELL_HPP_

	#include "Errors.hpp"

	class ErrorsShell: public Errors {
	public:
		ErrorsShell(std::ostream &, const std::string &) throw();
		virtual ~ErrorsShell(void) throw();
	};

#endif /* !ERRORS_SHELL_HPP_ */
