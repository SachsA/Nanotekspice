//
// EPITECH PROJECT, 2018
// Nano
// File description:
// input hpp
//

#ifndef INPUT_HPP_
	#define INPUT_HPP_

	#include <exception>
	#include "IComponent.hpp"
	#include "ErrorsLink.hpp"

	class Input : public nts::IComponent {
	public:
		// Ctor & Dtor
		Input(const std::string &name);
		Input(const std::string &name, nts::Tristate value,
		bool isLocked = false);
		~Input();
		// Setters
		void	setLink(std::size_t pin,
			nts::IComponent &other,
			std::size_t otherPin);
		void	setValue(nts::Tristate value, bool force = false);
		// Methods
		virtual nts::Tristate	compute(std::size_t pin = 1);
		void			dump() const;
	protected:
		std::string	_name;
		nts::Tristate	_value;
		bool		_locked;
		nts::Links	_link[1];
	};

#endif /* !INPUT_HPP_ */
