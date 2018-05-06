//
// EPITECH PROJECT, 2018
// Nano
// File description:
// FlipFlop hpp
//

#include "ErrorsPin.hpp"
#include "ErrorsLink.hpp"
#include "FlipFlop.hpp"

FlipFlop::FlipFlop()
{
}

FlipFlop::~FlipFlop()
{
}

///////////////// SETTERS //////////////////
void FlipFlop::setLink(std::size_t pin, nts::IComponent &other,
std::size_t otherPin)
{
	if (pin == 0 || pin > _maxPin)
		throw ErrorsLink(std::cerr, "The pin to link is out bounded");
	pin--;
	_links[pin].component = &other;
	_links[pin].pin = otherPin;
}

///////////////// METHODS //////////////////
void FlipFlop::processDeepCompute()
{
	nts::Tristate	reset = _links[2].component->compute(_links[2].pin);
	nts::Tristate	set = _links[4].component->compute(_links[4].pin);

	if (reset == nts::UNDEFINED || set == nts::UNDEFINED) {
		_q = nts::UNDEFINED;
		_qb = nts::UNDEFINED;
	} else if (reset == nts::TRUE) {
		if (set == nts::TRUE) {
			_q = nts::TRUE;
			_qb = nts::FALSE;
		} else {
			_q = nts::FALSE;
			_qb = nts::TRUE;
		}
	}
}

nts::Tristate FlipFlop::processCompute(size_t pin)
{
	nts::Tristate	reset = _links[3].component->compute(_links[3].pin);
	nts::Tristate	set = _links[5].component->compute(_links[5].pin);

	if (set == nts::FALSE && reset == nts::FALSE)
		this->processDeepCompute();
	else {
		_q = set;
		_qb = reset;
	}
	return (pin == 0) ? (_q) : (_qb);
}

nts::Tristate FlipFlop::compute(std::size_t pin)
{
	nts::Tristate ret;

	if (pin == 0 || pin > _maxPin)
		throw ErrorsPin(std::cerr, "The pin to compute is out bounded");
	--pin;
	if (pin == 0 || pin == 1) {
		if (_links[2].component == nullptr ||
		    _links[3].component == nullptr ||
		    _links[4].component == nullptr ||
		    _links[5].component == nullptr )
			throw ErrorsLink(std::cerr, "The pin to compute is not linked");
		ret = this->processCompute(pin);
	}
	else
		ret = nts::UNDEFINED;
	return ret;
}

void FlipFlop::dump() const
{
}
