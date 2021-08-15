#pragma once
#include <SFML/Graphics.hpp>
#include <Definitions.h>

class Bird
{
protected:
	sf::RenderWindow* window;
public:
	sf::Sprite birdSprite;
	sf::Texture birdTexture;

	Bird(sf::RenderWindow& window);
};

