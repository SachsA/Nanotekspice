//
// EPITECH PROJECT, 2018
// Nano Tek Spice
// File description:
// Inverter Cpp
//

#include "ErrorsPin.hpp"
#include "ErrorsLink.hpp"
#include "Inverter.hpp"

Inverter::Inverter()
{
	_links[0].component = nullptr;
	_links[1].component = nullptr;
	_links[0].pin = 0;
	_links[1].pin = 0;
}

Inverter::~Inverter()
{
}

///////////////// SETTERS //////////////////
void Inverter::setLink(std::size_t pin, nts::IComponent &other,
		       std::size_t otherPin)
{
	if (pin == 0 || pin > _maxPin)
		throw ErrorsLink(std::cerr, "The pin to link is out bounded");
	pin--;
	_links[pin].component = &other;
	_links[pin].pin = otherPin;
}

///////////////// METHODS //////////////////
nts::Tristate Inverter::calculate(nts::Tristate in)
{
	nts::Tristate val;

	if (in == nts::TRUE)
		val = nts::FALSE;
	else if (in == nts::FALSE)
		val = nts::TRUE;
	else
		val = nts::UNDEFINED;
	return val;
}

nts::Tristate Inverter::compute(std::size_t pin)
{
	nts::Tristate ret;

	Deep::compt -= 1;
	if (pin == 0 || pin > _maxPin)
		throw ErrorsPin(std::cerr, "The pin to compute is out bounded");
	if (!Deep::compt)
		throw ErrorsLink(std::cerr, "Bad link");
	--pin;
	if (pin == 1) {
		if (_links[0].component == nullptr)
			throw ErrorsLink(std::cerr, "Missing link");
		ret = Inverter::calculate(
			_links[0].component->compute(_links[0].pin));
	}
	else
		ret = nts::UNDEFINED;
	return ret;
}

void Inverter::dump() const
{
}
