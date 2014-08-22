#include "testlib/ScreenManager.hpp"

ScreenManager::ScreenManager(sf::RenderWindow& w) : m_window(w), currentScreen(0)
{
}

void ScreenManager::mapScreen(int id, IScreen* s) 
{
	s->m_window  = &this->m_window;
	s->m_sm = this;
	mapa.emplace(id, s);
}

void ScreenManager::setCurrentScreen(int id) 
{
	currentScreen = id;
}

void ScreenManager::run() 
{
	while (m_window.isOpen())
	{
		sf::Event event;
		while (m_window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				m_window.close();

			mapa[currentScreen]->processEvent(event);
		}

		mapa[currentScreen]->update();
		mapa[currentScreen]->draw();
	}
}
