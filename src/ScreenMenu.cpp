#include "testlib/ScreenMenu.hpp"

ScreenMenu::ScreenMenu() 
{
	shape = sf::CircleShape(100.0f);
	shape.setFillColor(sf::Color::Blue);
}

void ScreenMenu::processEvent(sf::Event& event)
{
	if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Return) {
		m_sm->setCurrentScreen(0);
	}
}

void ScreenMenu::update()
{

}

void ScreenMenu::draw() 
{
	m_window->clear();
	m_window->draw(shape);
	m_window->display();
}
