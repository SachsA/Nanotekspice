//
// EPITECH PROJECT, 2018
// Nano
// File description:
// SixInverterGates cpp
//

#include "ErrorsPin.hpp"
#include "ErrorsLink.hpp"
#include "SixInverterGates.hpp"

SixInverterGates::SixInverterGates(const std::string &value)
: _name(value)
{
	_links[0] = {0, 1};
	_links[1] = {0, 2};
	_links[2] = {1, 1};	// Output
	_links[3] = {1, 2};	// Output
	_links[4] = {2, 1};
	_links[5] = {2, 2};
	_links[6] = {-1, -1};	// Null
	_links[7] = {3, 2};
	_links[8] = {3, 1};
	_links[9] = {4, 2};	// Output
	_links[10] = {4, 1};	// Output
	_links[11] = {5, 2};
	_links[12] = {5, 1};
	_links[13] = {-1, -1};	// Null
}

SixInverterGates::~SixInverterGates()
{
}

///////////////// SETTERS //////////////////
void	SixInverterGates::setLink(std::size_t pin, nts::IComponent &other,
std::size_t otherPin)
{
	size_t	gateIdx;
	size_t	gatePin;

	if (pin == 0 || pin > _maxPin)
		throw ErrorsLink(std::cerr, "The pin to link is out bounded");
	--pin;
	if (_links[pin].first == (long unsigned int) -1)
		throw ErrorsLink(std::cerr, "Invalid pin");
	_extern[pin].component = &other; 
	_extern[pin].pin = otherPin;
	gateIdx = _links[pin].first;
	gatePin = _links[pin].second;
	_containt[gateIdx].setLink(gatePin, other, otherPin);
}

///////////////// METHODS //////////////////
nts::Tristate	SixInverterGates::compute(std::size_t pin)
{
	size_t	gateIdx;
	size_t	gatePin;

	if (pin == 0 || pin > _maxPin)
		throw ErrorsPin(std::cerr, "The pin to compute is out bounded");
	--pin;
	gateIdx = _links[pin].first;
	gatePin = _links[pin].second;
	return _containt[gateIdx].compute(gatePin);
}

void		SixInverterGates::dump() const
{
}
