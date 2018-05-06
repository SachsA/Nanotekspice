//
// EPITECH PROJECT, 2018
// Nano Tek Spice
// File description:
// Inverter hpp
//

#ifndef INVERTER_HPP_
	#define INVERTER_HPP_

	#include "IComponent.hpp"
	#include "Deep.hpp"
	#include "ErrorsPin.hpp"
	#include "ErrorsLink.hpp"

	class Inverter : public nts::IComponent {
	public:
		// Ctor & Dtor
		Inverter();
		~Inverter();
		// Setters
		void	setLink(std::size_t pin,
			nts::IComponent &other,
			std::size_t otherPin);
		// Methods
		static nts::Tristate	calculate(nts::Tristate in);
		nts::Tristate		compute(std::size_t pin = 1);
		void			dump() const;
	private:
		size_t		_maxPin = 2;
		nts::Links	_links[2];
		nts::Tristate	_val;
	};

#endif /* !INVERTER_HPP_ */
