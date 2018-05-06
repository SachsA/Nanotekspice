//
// EPITECH PROJECT, 2018
// Nano Tek Spice
// File description:
// Errors Link Hpp
//

#ifndef ERRORS_LINK_HPP_
	#define ERRORS_LINK_HPP_

	#include "Errors.hpp"

	class ErrorsLink: public Errors {
	public:
		ErrorsLink(std::ostream &, const std::string &) throw();
		virtual ~ErrorsLink(void) throw();
	};

#endif /* !ERRORS_LINK_HPP_ */
