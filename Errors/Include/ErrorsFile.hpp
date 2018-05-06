//
// EPITECH PROJECT, 2018
// Nano Tek Spice
// File description:
// Errors File Hpp
//

#ifndef ERRORS_FILE_HPP_
	#define ERRORS_FILE_HPP_

	#include "Errors.hpp"

	class ErrorsFile: public Errors {
	public:
		ErrorsFile(std::ostream &, const std::string &) throw();
		virtual ~ErrorsFile(void) throw();
	};

#endif /* !ERRORS_FILE_HPP_ */
