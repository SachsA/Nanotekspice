//
// EPITECH PROJECT, 2018
// Nano
// File description:
// Circuit cpp
//

#include <algorithm>
#include "Circuit.hpp"
#include "ErrorsLink.hpp"
#include "ErrorsInput.hpp"

bool Circuit::state = false;

Circuit::Circuit()
{
}

Circuit::~Circuit()
{
}

/////////////////// OPERATOR ////////////////////
nts::IComponent	*Circuit::operator[](const std::string &name)
{
	if (_components.find(name) == _components.end())
		throw ErrorsInput(std::cerr, "'" + name + "': unknow component");
	return _components[name].get();
}

/////////////////// SETTERS /////////////////////
void	Circuit::setLink(std::size_t pin, nts::IComponent &other,
std::size_t otherPin)
{
	(void) pin;
	(void) other;
	(void) otherPin;
}

void	Circuit::setLink(const Born &first_pair, const Born &second_pair)
{
	IComponent	*first_compo;
	IComponent	*second_compo;

	if (_components.find(first_pair.first) == _components.end())
		throw ErrorsLink(std::cerr, "'" + first_pair.first + "': unknow component");
	if (_components.find(second_pair.first) == _components.end())
		throw ErrorsLink(std::cerr, "'" + second_pair.first + "': unknow component");
	first_compo = _components[first_pair.first].get();
	second_compo = _components[second_pair.first].get();
	first_compo->setLink(first_pair.second,
				*second_compo, second_pair.second);
	second_compo->setLink(second_pair.second,
				*first_compo, first_pair.second);
}

/////////////////// METHODS /////////////////////
void		Circuit::addComponent(const std::string &type,
const std::string &name)
{
	unique_compo		compo;
	Output			*out;

	if (_components.find(name) != _components.end())
		throw ErrorsInput(std::cerr, "'" + name + "': name already used");
	compo = _fac.createComponent(type, name);
	if (type == "output") {
		out = dynamic_cast<Output*>(compo.get());
		_outputs.push_back(out);
	}
	_components.emplace(name, std::move(compo));
}

nts::Tristate	Circuit::compute(std::size_t pin)
{
	(void) pin;
	return nts::FALSE;
}

void		Circuit::simulate()
{
	for (auto target : _outputs) {
		Deep::compt = 10000;
		target->compute();
	}
	Circuit::state = !Circuit::state;
}

bool sort_ascii(Output *i, Output *j) {
	return (i->_name < j->_name);
}

void		Circuit::display()
{
	std::sort(_outputs.begin(), _outputs.end(), sort_ascii);
	for (auto target : _outputs) {
		target->dump();
	}
}

void		Circuit::dump() const
{
}
