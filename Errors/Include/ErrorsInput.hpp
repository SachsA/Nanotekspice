//
// EPITECH PROJECT, 2018
// Nano Tek Spice
// File description:
// Errors Input Hpp
//

#ifndef ERRORS_INPUT_HPP_
	#define ERRORS_INPUT_HPP_

	#include "Errors.hpp"

	class ErrorsInput: public Errors {
	public:
		ErrorsInput(std::ostream &, const std::string &) throw();
		virtual ~ErrorsInput(void) throw();
	};

#endif /* !ERRORS_INPUT_HPP_ */
