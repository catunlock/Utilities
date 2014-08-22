#include "testlib/SpaceBackgroundRandom.hpp"

SpaceBackgroundRandom::SpaceBackgroundRandom() :
	m_min(0),
	m_max(0)
{

}

SpaceBackgroundRandom::SpaceBackgroundRandom(int min, int max) :
	m_min(min),
	m_max(max),
	distribution(min, max)
{
}

int SpaceBackgroundRandom::getNumber() {
	return distribution(generator);
}

void SpaceBackgroundRandom::setMin(int min) {
	distribution = std::uniform_int_distribution<int>(min, m_max);
	m_min = min;
}

void SpaceBackgroundRandom::setMax(int max) {
	distribution = std::uniform_int_distribution<int>(m_min, max);
	m_max = max;
}

int SpaceBackgroundRandom::getMax() {
	return m_max;
}

int SpaceBackgroundRandom::getMin() {
	return m_min;
}