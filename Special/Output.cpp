//
// EPITECH PROJECT, 2018
// Nano
// File description:
// Output cpp
//

#include "ErrorsPin.hpp"
#include "ErrorsLink.hpp"
#include "Circuit.hpp"
#include "Output.hpp"

Output::Output(const std::string &name)
: _name(name), _value(nts::UNDEFINED), _link(), _save(!Circuit::state)
{
}

Output::~Output()
{
}

/////////////////// SETTERS /////////////////////
void	Output::setLink(std::size_t pin, nts::IComponent &other,
std::size_t otherPin)
{
	--pin;
	if (pin > 0)
		throw ErrorsLink(std::cerr, "The pin to link is out bounded");
	_link[pin].component = &other;
	_link[pin].pin = otherPin;
}

/////////////////// METHODS /////////////////////
nts::Tristate	Output::compute(std::size_t pin)
{
	auto	target = _link[0].component;

	--pin;
	if (pin > 0)
		throw ErrorsPin(std::cerr, "The pin to compute is out bounded");
	if (_save == Circuit::state)
		throw ErrorsLink(std::cerr, "Multiple computing of an Output");
	_save = !_save;
	if (target == nullptr)
		throw ErrorsLink(std::cerr, "Unlinked output");
	_value = target->compute(_link[pin].pin);
	return _value;
}

void		Output::dump() const
{
	char	status = 'U';

	if (_value == nts::TRUE)
		status = '1';
	else if (_value == nts::FALSE)
		status = '0';
	std::cout << _name << "=" << status << std::endl;
}
