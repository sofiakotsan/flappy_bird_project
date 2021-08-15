#pragma once
#include <SFML/Graphics.hpp>
#include <Definitions.h>

class Bird
{
public:
	sf::Sprite birdSprite;
	sf::Texture birdTexture;

	Bird(sf::RenderWindow& window);
};

