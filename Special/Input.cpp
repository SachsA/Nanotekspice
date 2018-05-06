//
// EPITECH PROJECT, 2018
// Nano
// File description:
// Input cpp
//

#include "Input.hpp"
#include "ErrorsLink.hpp"
#include "ErrorsInput.hpp"

Input::Input(const std::string &name)
: _name(name), _value(nts::UNDEFINED), _locked(false)
{
}

Input::Input(const std::string &name, nts::Tristate value, bool isLocked)
: _name(name), _value(value), _locked(isLocked)
{
}

Input::~Input()
{
}

/////////////////// SETTERS /////////////////////
void	Input::setLink(std::size_t pin, nts::IComponent &other,
std::size_t otherPin)
{
	--pin;
	if (pin > 0)
		throw ErrorsLink(std::cerr, "The pin to link is out bounded");
	_link[pin].component = &other;
	_link[pin].pin = otherPin;
}

void	Input::setValue(nts::Tristate value, bool force)
{
	if (_locked && !force)
		std::cerr << "You can't change a locked value" << std::endl;
	else
		_value = value;
}

/////////////////// METHODS /////////////////////
nts::Tristate	Input::compute(std::size_t pin)
{
	--pin;
	if (pin > 0)
		throw ErrorsInput(std::cerr, "The pin to compute is out bounded");
	return _value;
}

void		Input::dump() const
{
}
