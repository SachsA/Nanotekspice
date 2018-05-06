//
// EPITECH PROJECT, 2018
// Nano Tek Spice
// File description:
// Nor cpp
//

#include "ErrorsPin.hpp"
#include "ErrorsLink.hpp"
#include "Nor.hpp"

Nor::Nor()
{
	_links[0].component = nullptr;
	_links[1].component = nullptr;
	_links[2].component = nullptr;
	_links[0].pin = 0;
	_links[1].pin = 0;
	_links[2].pin = 0;
}

Nor::~Nor()
{
}

///////////////// SETTERS //////////////////
void Nor::setLink(std::size_t pin, nts::IComponent &other,
		  std::size_t otherPin)
{
	if (pin == 0 || pin > _maxPin)
		throw ErrorsLink(std::cerr, "The pin to link is out bounded");
	pin--;
	_links[pin].component = &other;
	_links[pin].pin = otherPin;
}

///////////////// METHODS //////////////////
nts::Tristate Nor::calculate(nts::Tristate in1, nts::Tristate in2)
{
	nts::Tristate val;

	if (in1 == nts::TRUE || in2 == nts::TRUE)
		val = nts::FALSE;
	else if (in1 == nts::UNDEFINED || in2 == nts::UNDEFINED)
		val = nts::UNDEFINED;
	else
		val = nts::TRUE;
	return val;
}

nts::Tristate Nor::compute(std::size_t pin)
{
	nts::Tristate ret;

	Deep::compt -= 1;
	if (pin == 0 || pin > _maxPin)
		throw ErrorsPin(std::cerr, "The pin to compute is out bounded");
	if (!Deep::compt)
		throw ErrorsLink(std::cerr, "Bad link");
	--pin;
	if (pin == 2) {
		if (_links[0].component == nullptr ||
		    _links[1].component == nullptr)
			throw ErrorsLink(std::cerr, "Missing link");
		ret = Nor::calculate(
			_links[0].component->compute(_links[0].pin),
			_links[1].component->compute(_links[1].pin));
	}
	else
		ret = nts::UNDEFINED;
	return ret;
}

void Nor::dump() const
{
}
