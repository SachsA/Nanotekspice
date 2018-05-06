//
// EPITECH PROJECT, 2018
// Nano Tek Spice
// File description:
// Sum hpp
//

#ifndef SUM_HPP_
	#define SUM_HPP_

	#include "IComponent.hpp"
	#include "Or.hpp"
	#include "Xor.hpp"
	#include "And.hpp"

	class Sum : public nts::IComponent {
	public:
		// Ctor & Dtor
		Sum();
		Sum(const std::string &value);
		~Sum();
		// Setters
		void	setLink(std::size_t pin,
			nts::IComponent &other,
			std::size_t otherPin);
		// Methods
		static nts::Tristate	calculateS(nts::Tristate in1,
		nts::Tristate in2, nts::Tristate in3);
		static nts::Tristate	calculateC(nts::Tristate in1,
		nts::Tristate in2, nts::Tristate in3);
		nts::Tristate		processCompute(size_t pin);
		nts::Tristate		compute(std::size_t pin = 1);
		void			dump() const;
	private:
		const std::string		_name;
		size_t				_maxPin = 5;
		nts::Links			_links[5];
	};

#endif /* !SUM_HPP_ */
