//
// EPITECH PROJECT, 2018
// Nano
// File description:
// Tester Gates hpp
//

#ifndef GATES_HPP_
	#define GATES_HPP_

	#include <vector>
	#include "Tester.hpp"
	#include "And.hpp"
	#include "Inverter.hpp"
	#include "Nand.hpp"
	#include "Nor.hpp"
	#include "Or.hpp"
	#include "Xor.hpp"

	typedef nts::Tristate (*FuncTest)(nts::Tristate, nts::Tristate);
	using Inputs = std::pair<nts::Tristate, nts::Tristate>;

	class Gates {
	public:
		Gates();
		~Gates();
		void	setVerbose(int verbose);
		//
		size_t	gatesFull();
		size_t	gatesAnd();
		size_t	gatesInverter();
		size_t	gatesNand();
		size_t	gatesNor();
		size_t	gatesOr();
		size_t	gatesXor();
	private:
		int			_verbose;
		std::vector<Inputs>	_tests;
		//
		size_t	gatesCompare();
		size_t	gatesSimulate(nts::Tristate truth[9], FuncTest ptr);
	};

#endif /* !GATES_HPP_ */
