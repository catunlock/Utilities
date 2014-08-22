#pragma once
#include "Config.hpp"
#include "ScreenManager.hpp"
#include <SFML/Graphics.hpp>

class ScreenManager;
class TESTLIB_API IScreen 
{
	friend class ScreenManager;
public:
	virtual ~IScreen() {}
	virtual void processEvent(sf::Event& event) = 0;
	virtual void update() = 0;
	virtual void draw() = 0;

protected:
	sf::RenderWindow* m_window;
	ScreenManager* m_sm;
};
