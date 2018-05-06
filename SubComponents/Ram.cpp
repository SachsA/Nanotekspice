//
// EPITECH PROJECT, 2018
// Nano Tek Spice
// File description:
// Ram Cpp
//

#include "ErrorsPin.hpp"
#include "ErrorsLink.hpp"
#include "Ram.hpp"

Ram::Ram()
{
}

Ram::~Ram()
{
}

///////////////// SETTERS //////////////////
void Ram::setLink(std::size_t pin, nts::IComponent &other,
std::size_t otherPin)
{
	if (pin == 0 || pin > _maxPin)
		throw ErrorsLink(std::cerr, "The pin to link is out bounded");
	pin--;
	_links[pin].component = &other;
	_links[pin].pin = otherPin;
}

///////////////// METHODS //////////////////
nts::Tristate Ram::compute(std::size_t pin)
{
	nts::Tristate ret = nts::UNDEFINED;

	pin = pin;
	return ret;
}

void Ram::dump() const
{
}
