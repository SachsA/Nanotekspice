//
// EPITECH PROJECT, 2018
// Nano
// File description:
// Clock cpp
//

#include "Clock.hpp"
#include "Circuit.hpp"
#include "Xor.hpp"
#include "ErrorsPin.hpp"

Clock::Clock(const std::string &name) : Input(name, nts::UNDEFINED, true)
{
}

Clock::~Clock()
{
}

///////////////// METHODS //////////////////////
nts::Tristate	Clock::compute(std::size_t pin)
{
	nts::Tristate	state = nts::FALSE;

	--pin;
	if (pin > 0)
		throw ErrorsPin(std::cerr, "The pin to compute is out bounded");
	if (Circuit::state)
		state = nts::TRUE;
	return Xor::calculate(state, _value);
}
