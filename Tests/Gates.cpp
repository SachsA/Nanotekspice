//
// EPITECH PROJECT, 2018
// Nano
// File description:
// Tester Gates
//

#include "Gates.hpp"

Gates::Gates() : _verbose(0)
{
	_tests.push_back({nts::TRUE, nts::TRUE});
	_tests.push_back({nts::TRUE, nts::FALSE});
	_tests.push_back({nts::TRUE, nts::UNDEFINED});
	_tests.push_back({nts::FALSE, nts::TRUE});
	_tests.push_back({nts::FALSE, nts::FALSE});
	_tests.push_back({nts::FALSE, nts::UNDEFINED});
	_tests.push_back({nts::UNDEFINED, nts::TRUE});
	_tests.push_back({nts::UNDEFINED, nts::FALSE});
	_tests.push_back({nts::UNDEFINED, nts::UNDEFINED});
}

Gates::~Gates()
{
	_tests.clear();
}

void	Gates::setVerbose(int verbose)
{
	_verbose = verbose;
}

size_t	Gates::gatesSimulate(nts::Tristate truth[9], FuncTest ptr)
{
	nts::Tristate	get;
	size_t		ret = 0;

	for (int it = 0; it < 9; ++it) {
		if (_verbose >= 2)
			printf("\e[93mTest %i [\e[96m%i\e[93m,\e[96m%i"
			"\e[93m]\t", it, _tests[it].first, _tests[it].second);
		get = ptr(_tests[it].first, _tests[it].second);
		if (_verbose >= 2 && get == truth[it]) {
			printf("\e[92mOK\n");
		} else if (_verbose >= 2) {
			printf("\e[91mKO - %i != %i\n", get, truth[it]);
			ret++;
		}
	}
	if (_verbose >= 1)
		printf("\e[96mFailed tests\t%li\n", ret);
	return ret;
}

size_t	Gates::gatesAnd()
{
	nts::Tristate	truth[9];
	
	truth[0] = nts::TRUE;
	truth[1] = nts::FALSE;
	truth[2] = nts::UNDEFINED;
	truth[3] = nts::FALSE;
	truth[4] = nts::FALSE;
	truth[5] = nts::FALSE;
	truth[6] = nts::UNDEFINED;
	truth[7] = nts::FALSE;
	truth[8] = nts::UNDEFINED;
	return this->gatesSimulate(truth, &And::calculate);
}

size_t	Gates::gatesInverter()
{
	size_t		ret = 0;

	if (Inverter::calculate(nts::TRUE) != nts::FALSE) {
		printf("\e[91mKO - !TRUE != FALSE\n");
		++ret;
	}
	if (Inverter::calculate(nts::FALSE) != nts::TRUE) {
		printf("\e[91mKO - !FALSE != TRUE\n");
		++ret;
	}
	if (Inverter::calculate(nts::UNDEFINED) != nts::UNDEFINED) {
		printf("\e[91mKO - !UNDEFINED != UNDEFINED\n");
		++ret;
	}
	if (_verbose >= 1 && !ret)
		printf("\e[96mAll tests passed\n");
	else if (_verbose >= 1)
		printf("\e[96mFailed tests\t%li\n", ret);
	return ret;
}

size_t	Gates::gatesNand()
{
	nts::Tristate	truth[9];
	
	truth[0] = nts::FALSE;
	truth[1] = nts::TRUE;
	truth[2] = nts::UNDEFINED;
	truth[3] = nts::TRUE;
	truth[4] = nts::TRUE;
	truth[5] = nts::TRUE;
	truth[6] = nts::UNDEFINED;
	truth[7] = nts::TRUE;
	truth[8] = nts::UNDEFINED;
	return this->gatesSimulate(truth, &Nand::calculate);
}

size_t	Gates::gatesNor()
{
	nts::Tristate	truth[9];
	
	truth[0] = nts::FALSE;
	truth[1] = nts::FALSE;
	truth[2] = nts::FALSE;
	truth[3] = nts::FALSE;
	truth[4] = nts::TRUE;
	truth[5] = nts::UNDEFINED;
	truth[6] = nts::FALSE;
	truth[7] = nts::UNDEFINED;
	truth[8] = nts::UNDEFINED;
	return this->gatesSimulate(truth, &Nor::calculate);
}

size_t	Gates::gatesOr()
{
	nts::Tristate	truth[9];
	
	truth[0] = nts::TRUE;
	truth[1] = nts::TRUE;
	truth[2] = nts::TRUE;
	truth[3] = nts::TRUE;
	truth[4] = nts::FALSE;
	truth[5] = nts::UNDEFINED;
	truth[6] = nts::TRUE;
	truth[7] = nts::UNDEFINED;
	truth[8] = nts::UNDEFINED;
	return this->gatesSimulate(truth, &Or::calculate);
}

size_t	Gates::gatesXor()
{
	nts::Tristate	truth[9];
	
	truth[0] = nts::FALSE;
	truth[1] = nts::TRUE;
	truth[2] = nts::UNDEFINED;
	truth[3] = nts::TRUE;
	truth[4] = nts::FALSE;
	truth[5] = nts::UNDEFINED;
	truth[6] = nts::UNDEFINED;
	truth[7] = nts::UNDEFINED;
	truth[8] = nts::UNDEFINED;
	return this->gatesSimulate(truth, &Xor::calculate);
}

size_t	Gates::gatesFull()
{
	size_t	ret = 0;

	printf("\e[90m===== Gates test =====\n");
	printf("\e[94m--- Gate And ---\n");
	ret += this->gatesAnd();
	printf("\e[94m--- Gate Nand ---\n");
	ret += this->gatesNand();
	printf("\e[94m--- Gate Inverter ---\n");
	ret += this->gatesInverter();
	printf("\e[94m--- Gate Nor ---\n");
	ret += this->gatesNor();
	printf("\e[94m--- Gate Or ---\n");
	ret += this->gatesOr();
	printf("\e[94m--- Gate Xor ---\n");
	ret += this->gatesXor();
	printf("\e[90m===== Failed tests %li\n", ret);
	return ret;
}