#pragma once
#include <SFML/Graphics.hpp>
#include <Definitions.h>

class Bird
{
public:
	sf::Sprite birdSprite;
	sf::Texture birdTexture;

	Bird()
	{
		//sf::Texture()
		//birdTexture.se

		
		birdTexture.loadFromFile(BIRD_SPRITE_PATH);

		birdSprite.setTexture(birdTexture);

		
	}
};

