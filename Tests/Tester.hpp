//
// EPITECH PROJECT, 2018
// Nano
// File description:
// Tester header
//

#ifndef TESTER_HPP_
	#define TESTER_HPP_

	#include <cstdio>
	#include <utility>
	#include <stack>
	#include "IComponent.hpp"

	using Out = std::stack<nts::Tristate>;
	using Result = std::pair<size_t, size_t>;

	void GatesTests();

#endif /* !TESTER_HPP_ */
