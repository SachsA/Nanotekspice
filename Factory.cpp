//
// EPITECH PROJECT, 2018
// Nano
// File description:
// Factory cpp
//

#include "Factory.hpp"
#include "ErrorsChipset.hpp"

Factory::Factory()
{
	_creator["input"] = &Factory::createInput;
	_creator["output"] = &Factory::createOutput;
	_creator["clock"] = &Factory::createClock;
	_creator["true"] = &Factory::createTrue;
	_creator["false"] = &Factory::createFalse;
	_creator["4001"] = &Factory::create4001;
	_creator["4008"] = &Factory::create4008;
	_creator["4011"] = &Factory::create4011;
	_creator["4013"] = &Factory::create4013;
	_creator["4030"] = &Factory::create4030;
	_creator["4069"] = &Factory::create4069;
	_creator["4071"] = &Factory::create4071;
	_creator["4081"] = &Factory::create4081;
}

Factory::~Factory()
{
}

////////////////////// METHODS ////////////////
unique_compo	Factory::createComponent(const std::string &type,
					 const std::string &value)
{
	funcPtr		ptr;

	if (_creator.find(type) == _creator.end())
		throw ErrorsChipset(std::cerr, "'" + type + "': unknow chipset's type");
	ptr = _creator[type];
	return (this->*ptr)(value);
}

///////////////////// PRIVATE METHODS /////////////
unique_compo	Factory::createInput(const std::string &value)
	const noexcept
{
	nts::IComponent	*ret = new Input(value);

	return unique_compo(ret);
}

unique_compo	Factory::createOutput(const std::string &value)
	const noexcept
{
	nts::IComponent	*ret = new Output(value);

	return unique_compo(ret);
}

unique_compo	Factory::createClock(const std::string &value)
	const noexcept
{
	nts::IComponent	*ret = new Clock(value);

	return unique_compo(ret);
}

unique_compo	Factory::createTrue(const std::string &value)
	const noexcept
{
	nts::IComponent	*ret = new Input(value, nts::TRUE, true);

	return unique_compo(ret);
}

unique_compo	Factory::createFalse(const std::string &value)
	const noexcept
{
	nts::IComponent	*ret = new Input(value, nts::FALSE, true);

	return unique_compo(ret);
}

unique_compo	Factory::create4001(const std::string &value)
	const noexcept
{
	return unique_compo(new FourBasicGates<Nor>(value));
}

unique_compo	Factory::create4008(const std::string &value)
	const noexcept
{
	return unique_compo(new Adder(value));
}

unique_compo	Factory::create4011(const std::string &value)
	const noexcept
{
	return unique_compo(new FourBasicGates<Nand>(value));
}

unique_compo	Factory::create4013(const std::string &value)
	const noexcept
{
	return unique_compo(new DualFlipFlop(value));
}

unique_compo	Factory::create4030(const std::string &value)
	const noexcept
{
	return unique_compo(new FourBasicGates<Xor>(value));
}

unique_compo	Factory::create4069(const std::string &value)
	const noexcept
{
	return unique_compo(new SixInverterGates(value));
}

unique_compo	Factory::create4071(const std::string &value)
	const noexcept
{
	return unique_compo(new FourBasicGates<Or>(value));
}

unique_compo	Factory::create4081(const std::string &value)
	const noexcept
{
	return unique_compo(new FourBasicGates<And>(value));
}
