//
// EPITECH PROJECT, 2018
// Nano
// File description:
// FlipFlop hpp
//

#ifndef FLIPFLOP_HPP_
	#define FLIPFLOP_HPP_

	#include "IComponent.hpp"

	class FlipFlop {
	public:
		// Ctor & Dtor
		FlipFlop();
		~FlipFlop();
		// Setters
		void	setLink(std::size_t pin,
			nts::IComponent &other,
			std::size_t otherPin);
		// Methods
		void			processDeepCompute();
		nts::Tristate		processCompute(size_t pin);
		nts::Tristate		compute(std::size_t pin = 1);
		void			dump() const;
	private:
		size_t				_maxPin = 6;
		nts::Links			_links[6];
		nts::Tristate			_q = nts::UNDEFINED;
		nts::Tristate			_qb = nts::UNDEFINED;
	};

#endif /* !FLIPFLOP_HPP_ */
