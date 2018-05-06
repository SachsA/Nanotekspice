//
// EPITECH PROJECT, 2018
// Nano Tek Spice
// File description:
// Errors Chipsets Hpp
//

#ifndef ERRORS_CHIPSET_HPP_
	#define ERRORS_CHIPSET_HPP_

	#include "Errors.hpp"

	class ErrorsChipset: public Errors {
	public:
		ErrorsChipset(std::ostream &, const std::string &) throw();
		virtual ~ErrorsChipset(void) throw();
	};

#endif /* !ERRORS_CHIPSET_HPP_ */
