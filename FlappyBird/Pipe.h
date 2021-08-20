#pragma once
#include <Definitions.h>
#include <SFML/Graphics.hpp>

class Pipe
{
	sf::RenderWindow* window;
public:
	sf::Sprite topPipeSprite;
	sf::Texture topPipeTexture;

	sf::Sprite bottomPipeSprite;
	sf::Texture bottomPipeTexture;

	Pipe(sf::RenderWindow& window);
	Pipe(const Pipe& pipe);

	void renderTopPipe();
	void renderBottomPipe();
};

