#pragma once
#include <Definitions.h>
#include <SFML/Graphics.hpp>
#include <time.h>

class Pipe
{
	sf::RenderWindow* window;
public:
	sf::Sprite topPipeSprite;
	sf::Texture topPipeTexture;

	sf::Sprite bottomPipeSprite;
	sf::Texture bottomPipeTexture;

	Pipe(sf::RenderWindow& window, int freeSpaceSize);
	Pipe(const Pipe& pipe);

	void renderTopPipe();
	void renderBottomPipe();
};

