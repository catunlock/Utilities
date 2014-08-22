#include "testlib/FPSCounter.hpp"
#include <sstream>

FPSCounter::FPSCounter(sf::Font& font) :
fps(0),
elapsedTime(0)
{
	setFont(font);
	setCharacterSize(30);
	setStyle(sf::Text::Regular);
	setString("0");
	setColor(sf::Color::Yellow);
}


FPSCounter::~FPSCounter()
{
}

static inline std::string int2Str(int x)
{
	std::stringstream type;
	type << x;
	return type.str();
}

void FPSCounter::tick()
{
	++fps;
	elapsedTime += timer.restart().asMilliseconds();
	if (elapsedTime >= 1000) {
		setString(int2Str(fps));
		elapsedTime = 0;
		fps = 0;
	}
}
