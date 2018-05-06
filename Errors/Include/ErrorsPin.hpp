//
// EPITECH PROJECT, 2018
// Nano Tek Spice
// File description:
// Errors Pin Hpp
//

#ifndef ERRORS_PIN_HPP_
	#define ERRORS_PIN_HPP_

	#include "ErrorsChipset.hpp"

	class ErrorsPin: public ErrorsChipset {
	public:
		ErrorsPin(std::ostream &, const std::string &) throw();
		virtual ~ErrorsPin(void) throw();
	};

#endif /* !ERRORS_PIN_HPP_ */
