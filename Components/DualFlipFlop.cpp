//
// EPITECH PROJECT, 2018
// Nano
// File description:
// 4013 cpp
//

#include "ErrorsPin.hpp"
#include "ErrorsLink.hpp"
#include "DualFlipFlop.hpp"

DualFlipFlop::DualFlipFlop(const std::string &value) : _name(value)
{
	_links[0] = {0, 1};	// Output
	_links[1] = {0, 2};	// Output
	_links[2] = {0, 3};
	_links[3] = {0, 4};
	_links[4] = {0, 5};
	_links[5] = {0, 6};
	_links[6] = {-1, -1};	// Null
	_links[7] = {1, 1};	// Output
	_links[8] = {1, 2};	// Output
	_links[9] = {1, 3};
	_links[10] = {1, 4};
	_links[11] = {1, 5};
	_links[12] = {1, 6};
	_links[13] = {-1, -1};	// Null
}

DualFlipFlop::~DualFlipFlop()
{
}

///////////////// SETTERS //////////////////
void	DualFlipFlop::setLink(std::size_t pin, nts::IComponent &other,
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
nts::Tristate	DualFlipFlop::compute(std::size_t pin)
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

void		DualFlipFlop::dump() const
{
}
