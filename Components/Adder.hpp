//
// EPITECH PROJECT, 2018
// Nano Tek Spice
// File description:
// Adder hpp
//

#ifndef ADDER_HPP_
	#define ADDER_HPP_

	#include "IComponent.hpp"
	#include "Sum.hpp"

	class Adder : public nts::IComponent {
	public:
		// Ctor & Dtor
		Adder(const std::string &value);
		~Adder();
		// Setters
		void	setLink(std::size_t pin,
			nts::IComponent &other,
			std::size_t otherPin);
		// Methods
		nts::Tristate	compute(std::size_t pin = 1);
		void		dump() const;
	private:
		const std::string		_name;
		size_t				_maxPin = 16;
		std::pair<size_t, size_t>	_links[16] = {{-1, -1}};
		nts::Links			_extern[16];
		Sum				_containt[4];
	};

#endif /* !ADDER_HPP_ */
