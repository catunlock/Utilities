#pragma once
#include "Config.hpp"
#include "IScreen.hpp"
#include <SFML/Graphics.hpp>

class TESTLIB_API ScreenGame : public IScreen 
{
public:
	ScreenGame();

	void processEvent(sf::Event& event) override;

	void update() override;

	void draw() override;

private:
	sf::CircleShape shape;
};