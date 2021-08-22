#pragma once
#include <SFML/Graphics.hpp>
#include <Definitions.h>

class Ground
{
protected:
	sf::RenderWindow* window;
public:
	sf::Sprite groundSprite;
	sf::Texture groundTexture;

	Ground(sf::RenderWindow& window);
};