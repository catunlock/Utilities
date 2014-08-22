#include "testlib/TextureSet.hpp"

TextureSet::TextureSet(int max_textures) :
	max_textures(max_textures),
	num_textures(0),
	textures(max_textures)
{
	if (max_textures < 1) {
		throw std::invalid_argument("The number of textures of a TextureSet can't be minor of 1.");
	}
}

void TextureSet::addTexture(sf::Texture& t)
{
	if (num_textures < max_textures) {
		textures[num_textures] = t;
		++num_textures;
	}
	else {
		throw std::runtime_error("The TextureSet is full.");
	}
}

void TextureSet::deleteTexture(int i) {
	if (i >= 0 && i < num_textures) {
		for (int j = i; j < num_textures - 1; ++j){
			textures[j] = textures[j + 1];
		}
		--num_textures;
	}
	else {
		throw std::out_of_range("The argument is out of range of the TextureSet.");
	}	
}

sf::Texture& TextureSet::getTexture(int i) {
	return textures[i];
}

int TextureSet::size(){
	return num_textures;
}
