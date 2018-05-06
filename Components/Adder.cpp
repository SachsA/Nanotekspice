//
// EPITECH PROJECT, 2018
// Nano Tek Spice
// File description:
// Adder Cpp
//

#include "ErrorsPin.hpp"
#include "ErrorsLink.hpp"
#include "Adder.hpp"

Adder::Adder(const std::string &value)
: _name(value)
{
	_links[0] = {3, 2};
	_links[1] = {2, 1};
	_links[2] = {2, 2};
	_links[3] = {1, 1};
	_links[4] = {1, 2};
	_links[5] = {0, 1};
	_links[6] = {0, 2};
	_links[8] = {0, 3};
	_links[9] = {0, 5};
	_links[10] = {1, 5};
	_links[11] = {2, 5};
	_links[12] = {3, 5};
	_links[13] = {3, 4};
	_links[14] = {3, 1};
	_containt[3].setLink(3, _containt[2], 4);
	_containt[2].setLink(3, _containt[1], 4);
	_containt[1].setLink(3, _containt[0], 4);
}

Adder::~Adder()
{
}

///////////////// SETTERS //////////////////
void	Adder::setLink(std::size_t pin, nts::IComponent &other,
std::size_t otherPin)
{
	size_t	gateIdx;
	size_t	gatePin;

	if (pin == 0 || pin > _maxPin)
		throw ErrorsLink(std::cerr, "The pin to link is out bounded");
	--pin;
	_extern[pin].component = &other; 
	_extern[pin].pin = otherPin;
	gateIdx = _links[pin].first;
	gatePin = _links[pin].second;
	_containt[gateIdx].setLink(gatePin, other, otherPin);
}

///////////////// METHODS //////////////////
nts::Tristate	Adder::compute(std::size_t pin)
{
	size_t	gateIdx;
	size_t	gatePin;

	if (pin == 0 || pin > _maxPin)
		throw ErrorsPin(std::cerr, "The pin to compute is out bounded");
	--pin;
	if (_links[pin].first == (long unsigned int) -1)
		throw ErrorsLink(std::cerr, "Invalid pin");
	gateIdx = _links[pin].first;
	gatePin = _links[pin].second;
	return _containt[gateIdx].compute(gatePin);
}

void		Adder::dump() const
{
}
