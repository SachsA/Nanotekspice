//
// EPITECH PROJECT, 2018
// Nano
// File description:
// SixInverterGates hpp
//

#ifndef SIXINVERTERGATES_HPP_
	#define SIXINVERTERGATES_HPP_

	#include "IComponent.hpp"
	#include "Inverter.hpp"

	class SixInverterGates : public nts::IComponent {
	public:
		// Ctor & Dtor
		SixInverterGates(const std::string &value);
		~SixInverterGates();
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
		Inverter			_containt[6];
	};

#endif /* !SIXINVERTERGATES_HPP_ */
