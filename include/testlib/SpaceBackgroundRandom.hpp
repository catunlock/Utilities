#pragma once
#include <random>
#include "testlib/Config.hpp"

class TESTLIB_API SpaceBackgroundRandom {
public:
	SpaceBackgroundRandom();
	SpaceBackgroundRandom(int min, int max);

	int getNumber();

	void setMin(int min);

	void setMax(int max);

	int getMax();

	int getMin();

private :
	std::uniform_int_distribution<int>  distribution;
	std::default_random_engine generator;

	int m_min, m_max;
};