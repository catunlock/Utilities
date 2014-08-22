#pragma once
#include <SFML/Graphics.hpp>
#include "testlib/Config.hpp"
#include "testlib/TextureSet.hpp"
#include "testlib/SpaceBackgroundRandom.hpp"

class TESTLIB_API SpaceBackground {
public:
	SpaceBackground(int windowWidth, sf::Texture& t1, sf::Texture& t2, int max_backgrounds);

	void addTexture(sf::Texture& t);

	void update();

	void setSpeed(int s);
public:
	sf::Sprite spriteCurrent;
	sf::Sprite spriteNext;
private:
	SpaceBackgroundRandom sbr;
	TextureSet textures;

	int i_texCurrent;
	int i_texNext;

	int windowWidth;
	int speed_space;
};