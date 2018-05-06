//
// EPITECH PROJECT, 2018
// Nano Tek Spice
// File description:
// Ram hpp
//

#ifndef RAM_HPP_
	#define RAM_HPP_

	#include "IComponent.hpp"

	class Ram {
	public:
		// Ctor & Dtor
		Ram();
		~Ram();
		// Setters
		void	setLink(std::size_t pin,
			nts::IComponent &other,
			std::size_t otherPin);
		// Methods
		nts::Tristate		compute(std::size_t pin = 1);
		void			dump() const;
	private:
		size_t				_maxPin = 6;
		nts::Links			_links[6];
	};

#endif /* !RAM_HPP_ */
