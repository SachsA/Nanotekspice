//
// EPITECH PROJECT, 2018
// Nano
// File description:
// output hpp
//

#ifndef OUTPUT_HPP_
	#define OUTPUT_HPP_

	#include <exception>
	#include "IComponent.hpp"

	class Output : public nts::IComponent {
	public:
		// Ctor & Dtor
		Output(const std::string &name);
		~Output();
		// Setters
		void	setLink(std::size_t pin,
			nts::IComponent &other,
			std::size_t otherPin);
		// Methods
		nts::Tristate	compute(std::size_t pin = 1);
		void		dump() const;
		std::string	_name;
	private:
		nts::Tristate	_value;
		nts::Links	_link[1];
		bool	_save;
	};

#endif /* !OUTPUT_HPP_ */
