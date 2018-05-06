//
// EPITECH PROJECT, 2018
// Nano
// File description:
// Clock hpp
//

#ifndef CLOCK_HPP_
	#define CLOCK_HPP_

	#include "Input.hpp"

	class Clock : public Input {
	public:
		// Ctor & Dtor
		Clock(const std::string &name);
		~Clock();
		// Methods
		nts::Tristate	compute(std::size_t pin = 1) override;
	};

#endif /* !CLOCK_HPP_ */
