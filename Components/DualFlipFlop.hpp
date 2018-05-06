//
// EPITECH PROJECT, 2018
// Nano
// File description:
// 4013 hpp
//

#ifndef DUALFLIPFLOP_HPP_
	#define DUALFLIPFLOP_HPP_

	#include "IComponent.hpp"
	#include "FlipFlop.hpp"

	class DualFlipFlop : public nts::IComponent {
	public:
		// Ctor & Dtor
		DualFlipFlop(const std::string &value);
		~DualFlipFlop();
		// Setters
		void	setLink(std::size_t pin,
				nts::IComponent &other,
				std::size_t otherPin);
		// Methods
		nts::Tristate	compute(std::size_t pin = 1);
		void		dump() const;
	private:
		const std::string		_name;
		size_t				_maxPin = 14;
		std::pair<size_t, size_t>	_links[14] = {{-1, -1}};
		nts::Links			_extern[14];
		FlipFlop			_containt[2];
	};

#endif /* !DUALFLIPFLOP_HPP_ */
