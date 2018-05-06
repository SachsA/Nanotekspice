//
// EPITECH PROJECT, 2018
// Nano
// File description:
// Factory hpp
//

#ifndef FACTORY_HPP_
	#define FACTORY_HPP_

	#include <memory>
	#include <string>
	#include <unordered_map>
	#include "IComponent.hpp"
	#include "FourBasicGates.hpp"
	#include "DualFlipFlop.hpp"
	#include "SixInverterGates.hpp"
	#include "Adder.hpp"
	#include "Input.hpp"
	#include "Output.hpp"

	class Factory;

	#include "Clock.hpp"

	using funcPtr = unique_compo (Factory::*)(const std::string &value)
	const noexcept;

	class Factory {
	public:
		// Ctor & Dtor
		Factory();
		~Factory();
		// Methods
		unique_compo	createComponent(
			const std::string &type,
			const std::string &value);
	private:
		std::unordered_map<std::string, funcPtr>	_creator;
		unique_compo	createInput(const std::string &value)
		const noexcept;
		unique_compo	createOutput(const std::string &value)
		const noexcept;
		unique_compo	createClock(const std::string &value)
		const noexcept;
		unique_compo	createTrue(const std::string &value)
		const noexcept;
		unique_compo	createFalse(const std::string &value)
		const noexcept;
		unique_compo	create4001(const std::string &value)
		const noexcept;
		unique_compo	create4008(const std::string &value)
		const noexcept;
		unique_compo	create4011(const std::string &value)
		const noexcept;
		unique_compo	create4013(const std::string &value)
		const noexcept;
		unique_compo	create4030(const std::string &value)
		const noexcept;
		unique_compo	create4069(const std::string &value)
		const noexcept;
		unique_compo	create4071(const std::string &value)
		const noexcept;
		unique_compo	create4081(const std::string &value)
		const noexcept;
	};

#endif /* !FACTORY_HPP_ */
