#include <Windows.h>
#include <SFML/Graphics.hpp>
#include <map>

const int ID_SCREEN_MENU = 0;
const int ID_SCREEN_GAME = 1;

class ScreenManager;
class IScreen {
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

class ScreenManager {
	
public:
	ScreenManager(sf::RenderWindow& w) : m_window(w), currentScreen(0)
	{

	}

	void mapScreen(int id, IScreen* s) {
		s->m_window  = &this->m_window;
		s->m_sm = this;
		mapa.emplace(id, s);
	}

	void setCurrentScreen(int id) {
		currentScreen = id;
	}

	void run() 
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
private:
	sf::RenderWindow& m_window;
	std::map<int, IScreen*> mapa;
	int currentScreen;
};



class ScreenGame : public IScreen {
public:
	ScreenGame() {
		shape = sf::CircleShape(100.f);
		shape.setFillColor(sf::Color::Green);
	}

	void processEvent(sf::Event& event) override {
		if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Return) {
			m_sm->setCurrentScreen(ID_SCREEN_MENU);
		}
	}

	void update() override {

	}

	void draw() override {
		m_window->clear();
		m_window->draw(shape);
		m_window->display();
	}

private:
	sf::CircleShape shape;
};

class ScreenMenu : public IScreen {
public:
	ScreenMenu() {
		shape = sf::CircleShape(100.0f);
		shape.setFillColor(sf::Color::Blue);
	}

	void processEvent(sf::Event& event) override {
		if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Return) {
			m_sm->setCurrentScreen(ID_SCREEN_GAME);
		}
	}

	void update() override {

	}

	void draw() override {
		m_window->clear();
		m_window->draw(shape);
		m_window->display();
	}

private:
	sf::CircleShape shape;
};