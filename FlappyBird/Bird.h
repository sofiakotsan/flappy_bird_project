#pragma once
#include <SFML/Graphics.hpp>
#include <Definitions.h>

class Bird
{
protected:
	sf::RenderWindow* window;
public:
	enum class BirdState {
		Falling, 
		Flying
	} birdState;

	sf::Clock flyingTime;
	sf::Sprite birdSprite;
	sf::Texture birdTexture;

	Bird(sf::RenderWindow& window);

	void Fly();
};

