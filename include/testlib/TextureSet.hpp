#pragma once
#include <vector>
#include <stdexcept>
#include <SFML/Graphics.hpp>
#include "testlib/Config.hpp"

class TESTLIB_API TextureSet {
public:
	TextureSet(int max_textures);

	void addTexture(sf::Texture& t);

	void deleteTexture(int i);

	sf::Texture& getTexture(int i);

	int size();

private:
	int num_textures;
	int max_textures;
	std::vector<sf::Texture> textures;
};