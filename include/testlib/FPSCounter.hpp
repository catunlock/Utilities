#pragma once
#include <SFML/Graphics.hpp>

class FPSCounter : public sf::Text
{
public:
	FPSCounter(sf::Font& font);
	virtual ~FPSCounter();

	void tick();
	
private:
	sf::Clock timer;
	sf::Uint32 fps;
	sf::Int32 elapsedTime;
};

