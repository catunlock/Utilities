#pragma once
#include "Config.hpp"
#include "IScreen.hpp"
#include <SFML/Graphics.hpp>

class TESTLIB_API ScreenMenu : public IScreen 
{
public:
	ScreenMenu();

	void processEvent(sf::Event& event) override;

	void update() override;

	void draw() override;

private:
	sf::CircleShape shape;
};