//
// EPITECH PROJECT, 2018
// Nano Tek Spice
// File description:
// Sum Cpp
//

#include "ErrorsPin.hpp"
#include "ErrorsLink.hpp"
#include "Sum.hpp"

Sum::Sum() : _name("none")
{
}

Sum::Sum(const std::string &value) : _name(value)
{
}

Sum::~Sum()
{
}

///////////////// SETTERS //////////////////
void Sum::setLink(std::size_t pin, nts::IComponent &other,
std::size_t otherPin)
{
	if (pin == 0 || pin > _maxPin)
		throw ErrorsLink(std::cerr, "The pin to link is out bounded");
	pin--;
	_links[pin].component = &other;
	_links[pin].pin = otherPin;
}

///////////////// METHODS //////////////////
nts::Tristate Sum::calculateS(nts::Tristate in1, nts::Tristate in2,
nts::Tristate in3)
{
	nts::Tristate	ret;

	ret = Xor::calculate(in1, in2);
	ret = Xor::calculate(ret, in3);
	return ret;
}

nts::Tristate Sum::calculateC(nts::Tristate in1, nts::Tristate in2,
nts::Tristate in3)
{
	nts::Tristate	step;
	nts::Tristate	ret;

	step = Xor::calculate(in1, in2);
	step = And::calculate(step, in3);
	ret = And::calculate(in1, in2);
	ret = Or::calculate(step, ret);
	return ret;
}

nts::Tristate Sum::processCompute(size_t pin)
{
	nts::Tristate	in1 = _links[0].component->compute(_links[0].pin);
	nts::Tristate	in2 = _links[1].component->compute(_links[1].pin);
	nts::Tristate	in3 = _links[2].component->compute(_links[2].pin);
	nts::Tristate	ret;

	if (pin == 3)
		ret = Sum::calculateC(in1, in2, in3);
	else
		ret = Sum::calculateS(in1, in2, in3);
	return ret;
}

nts::Tristate Sum::compute(std::size_t pin)
{
	nts::Tristate ret;

	if (pin == 0 || pin > _maxPin)
		throw ErrorsPin(std::cerr, "The pin to compute is out bounded");
	--pin;
	if (pin == 3 || pin == 4) {
		if (_links[0].component == nullptr ||
		    _links[1].component == nullptr ||
		    _links[2].component == nullptr)
			throw ErrorsLink(std::cerr, "The pin to link is out bounded");
		ret = this->processCompute(pin);
	}
	else
		ret = nts::UNDEFINED;
	return ret;
}

void Sum::dump() const
{
}
