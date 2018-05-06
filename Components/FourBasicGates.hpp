//
// EPITECH PROJECT, 2018
// Nano
// File description:
// FourBasicGates hpp
//

#ifndef FOURBASICGATES_HPP_
	#define FOURBASICGATES_HPP_

	#include "IComponent.hpp"
	#include "And.hpp"
	#include "Nand.hpp"
	#include "Or.hpp"
	#include "Xor.hpp"
	#include "Nor.hpp"
	#include "ErrorsPin.hpp"
	#include "ErrorsLink.hpp"

	template<typename T>
	class FourBasicGates : public nts::IComponent {
	public:
		// Ctor & Dtor
		FourBasicGates(const std::string &value) : _name(value) {
			_links[0] = {0, 1};
			_links[1] = {0, 2};
			_links[2] = {0, 3};	// Output
			_links[3] = {1, 3};	// Output
			_links[4] = {1, 2};
			_links[5] = {1, 1};
			_links[6] = {-1, -1};	// Null
			_links[7] = {2, 1};
			_links[8] = {2, 2};
			_links[9] = {2, 3};	// Output
			_links[10] = {3, 3};	// Output
			_links[11] = {3, 2};
			_links[12] = {3, 1};
			_links[13] = {-1, -1};	// Null
		};
		~FourBasicGates() = default;
		// Setters
		void	setLink(std::size_t pin,
				nts::IComponent &other,
				std::size_t otherPin) {
			size_t	gateIdx;
			size_t	gatePin;

			if (pin == 0 || pin > _maxPin)
				throw ErrorsLink(std::cerr, "The pin to link is out bounded");
			--pin;
			if (_links[pin].first == (long unsigned int) -1)
				throw ErrorsLink(std::cerr, "Invalid pin");
			_extern[pin].component = &other; 
			_extern[pin].pin = otherPin;
			gateIdx = _links[pin].first;
			gatePin = _links[pin].second;
			_containt[gateIdx].setLink(gatePin, other, otherPin);
		}
		// Methods
		nts::Tristate	compute(std::size_t pin = 1) {
			size_t	gateIdx;
			size_t	gatePin;

			if (pin == 0 || pin > _maxPin)
				throw ErrorsPin(std::cerr, "The pin to compute is out bounded");
			--pin;
			gateIdx = _links[pin].first;
			gatePin = _links[pin].second;
			return _containt[gateIdx].compute(gatePin);
		}
		void		dump() const {};
	protected:
		const std::string		_name;
		size_t				_maxPin = 14;
		std::pair<size_t, size_t>	_links[14] = {{-1, -1}};
		nts::Links			_extern[14];
	private:
		T				_containt[4];
	};

#endif /* !FOURBASICGATES_HPP_ */
