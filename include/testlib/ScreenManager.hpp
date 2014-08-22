#pragma once
#include "Config.hpp"
#include "IScreen.hpp"
#include <SFML/Graphics.hpp>

class IScreen;
class TESTLIB_API ScreenManager {
	
public:
	ScreenManager(sf::RenderWindow& w);

	void mapScreen(int id, IScreen* s);

	void setCurrentScreen(int id);

	void run();
	
private:
	sf::RenderWindow& m_window;
	std::map<int, IScreen*> mapa;
	int currentScreen;
};