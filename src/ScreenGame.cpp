#include "testlib/ScreenGame.hpp"

ScreenGame::ScreenGame() 
{
	shape = sf::CircleShape(100.f);
	shape.setFillColor(sf::Color::Green);
}

void ScreenGame::processEvent(sf::Event& event) 
{
	if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Return) {
		m_sm->setCurrentScreen(1);
	}
}

void ScreenGame::update()
{

}

void ScreenGame::draw()
{
	m_window->clear();
	m_window->draw(shape);
	m_window->display();
}
