//
// EPITECH PROJECT, 2018
// Nano Tek Spice
// File description:
// And hpp
//

#ifndef AND_HPP_
	#define AND_HPP_

	#include "IComponent.hpp"
	#include "Deep.hpp"
	#include "ErrorsPin.hpp"
	#include "ErrorsLink.hpp"

	class And : public nts::IComponent {
	public:
		// Ctor & Dtor
		And();
		~And();
		// Setters
		void	setLink(std::size_t pin,
			nts::IComponent &other,
			std::size_t otherPin);
		// Methods
		static nts::Tristate	calculate(nts::Tristate in1,
						  nts::Tristate in2);
		nts::Tristate		compute(std::size_t pin = 1);
		void			dump() const;
	private:
		size_t		_maxPin = 3;
		nts::Links	_links[3];
		nts::Tristate	_val;
	};

#endif /* !AND_HPP_ */
