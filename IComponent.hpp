//
// EPITECH PROJECT, 2018
// IComponent
// File description:
// Interface file
//

#ifndef ICOMPONENT_HPP_
	#define ICOMPONENT_HPP_

	namespace nts {
		class IComponent;
	}

	#include <iostream>
	#include <memory>

	using unique_compo = std::unique_ptr<nts::IComponent>;

namespace nts {
	enum Tristate {
		UNDEFINED = (-true),
		TRUE = true,
		FALSE = false
	};

	class IComponent {
	public:
		// Ctor & Dtor
		virtual ~IComponent() = default;
		// Setters
		virtual void	setLink(std::size_t pin,
				nts::IComponent &other,
				std::size_t otherPin) = 0;
		// Methods
		virtual nts::Tristate	compute(std::size_t pin = 1) = 0;
		virtual void		dump() const = 0;
	};

	struct Links {
		Links() {};
		//
		IComponent	*component;
		size_t		pin;
	};
}

#endif /* !ICOMPONENT_HPP_ */
