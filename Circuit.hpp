//
// EPITECH PROJECT, 2018
// Nano
// File description:
// Circuit hpp
//

#ifndef CIRCUIT_HPP_
	#define CIRCUIT_HPP_

	#include <vector>
	#include <unordered_map>
	#include <memory>
	#include "IComponent.hpp"
	#include "Factory.hpp"
	#include "Output.hpp"
	#include "Input.hpp"
	#include "Deep.hpp"

	using Map_type = std::unordered_map<std::string, unique_compo>;
	using Born = std::pair<std::string, size_t>;

	class Circuit : public nts::IComponent {
	public:
		// Ctor & Dtor
		Circuit();
		~Circuit();
		// Operator
		nts::IComponent	*operator[](const std::string &name);
		// Setters
		void	setLink(std::size_t pin,
			nts::IComponent &other,
			std::size_t otherPin);
		void	setLink(const Born &first, const Born &second);
		// Methods
		void	addComponent(const std::string &type,
		const std::string &name);
		void	setInputValue(std::string &name, int value);
		nts::Tristate	compute(std::size_t pin = 1);
		void		dump() const;
		void		simulate();
		void		display();
		static bool	state;
	private:
		Map_type					_components;
		std::vector<Output*>				_outputs;
		Factory						_fac;
	};

#endif /* !CIRCUIT_HPP_ */
