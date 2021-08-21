#include "Pipe.h"

Pipe::Pipe(sf::RenderWindow& _window, int freeSpaceSize) : window{ &_window }
{
	topPipeTexture.loadFromFile(BOTTOM_PIPE_PATH);
	bottomPipeTexture.loadFromFile(TOP_PIPE_PATH);

	topPipeSprite.setTexture(topPipeTexture);
	bottomPipeSprite.setTexture(bottomPipeTexture);

	topPipeSprite.setOrigin(0, topPipeSprite.getGlobalBounds().height);
	bottomPipeSprite.setOrigin(0, 0);
	//topPipeSprite.setOrigin(0, birdSprite.getTextureRect().height / 2);

	//birdSprite.setPosition(window->getSize().x / 9, window->getSize().y / 2);

	float topPipePos = rand()  % (freeSpaceSize - PIPE_GAP_HEIGHT - 50) + 25 ;
	//printf("a = %f\n", topPipePos);

	topPipeSprite.setPosition(window->getSize().x + topPipeSprite.getGlobalBounds().width, topPipePos);
	bottomPipeSprite.setPosition(window->getSize().x + topPipeSprite.getGlobalBounds().width, topPipePos + PIPE_GAP_HEIGHT);

}

Pipe::Pipe(const Pipe& pipe) 
{
	window = pipe.window;
	topPipeSprite.setPosition(pipe.topPipeSprite.getPosition().x, pipe.topPipeSprite.getPosition().y);
	bottomPipeSprite.setPosition(pipe.bottomPipeSprite.getPosition().x, pipe.bottomPipeSprite.getPosition().y);
}
