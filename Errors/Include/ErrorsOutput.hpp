//
// EPITECH PROJECT, 2018
// Nano Tek Spice
// File description:
// Errors Output Hpp
//

#ifndef ERRORS_OUTPUT_HPP_
	#define ERRORS_OUTPUT_HPP_

	#include "ErrorsLink.hpp"

	class ErrorsOutput: public ErrorsLink {
	public:
		ErrorsOutput(std::ostream &, const std::string &) throw();
		virtual ~ErrorsOutput(void) throw();
	};

#endif /* !ERRORS_OUTPUT_HPP_ */
