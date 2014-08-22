#include "testlib/SpaceBackground.hpp"

SpaceBackground::SpaceBackground(int windowWidth, sf::Texture& t1, sf::Texture& t2, int max_backgrounds) :
	textures(max_backgrounds),
	sbr(0, 1),
	windowWidth(windowWidth),
	speed_space(1)
{
	textures.addTexture(t1);
	textures.addTexture(t2);

	i_texCurrent = sbr.getNumber();
	i_texNext= sbr.getNumber();

	spriteCurrent.setTexture(textures.getTexture(i_texCurrent));
	spriteNext.setTexture(textures.getTexture(i_texNext));

	spriteNext.setPosition(windowWidth, 0);
}

void SpaceBackground::addTexture(sf::Texture& t) 
{
	textures.addTexture(t);
	sbr.setMax(sbr.getMax() + 1);
}

void SpaceBackground::update()
{
	sf::Vector2f posCurrent = spriteCurrent.getPosition();
	sf::Vector2f posNext = spriteNext.getPosition();

	posCurrent.x -= speed_space;
	posNext.x -= speed_space;

	if (posNext.x <= 0) {
		posNext.x = windowWidth;
		posCurrent.x = 0;
		
		spriteCurrent.setTexture(textures.getTexture(i_texNext));
		i_texCurrent = i_texNext;
		i_texNext = sbr.getNumber();
		spriteNext.setTexture(textures.getTexture(i_texNext));
	}

	spriteCurrent.setPosition(posCurrent);
	spriteNext.setPosition(posNext);
}

void SpaceBackground::setSpeed(int s)
{
	if (s > 0) {
		speed_space = s;
	}
	else {
		throw std::invalid_argument("The speed must be positive and greater than zero.");
	}
	
}