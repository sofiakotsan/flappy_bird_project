#include "Pipe.h"

Pipe::Pipe(sf::RenderWindow& _window) : window{ &_window }
{
	topPipeTexture.loadFromFile(BOTTOM_PIPE_PATH);
	bottomPipeTexture.loadFromFile(TOP_PIPE_PATH);

	topPipeSprite.setTexture(topPipeTexture);
	bottomPipeSprite.setTexture(bottomPipeTexture);

	topPipeSprite.setOrigin(0, topPipeSprite.getGlobalBounds().height);
	bottomPipeSprite.setOrigin(0, 0);
	//topPipeSprite.setOrigin(0, birdSprite.getTextureRect().height / 2);

	//birdSprite.setPosition(window->getSize().x / 9, window->getSize().y / 2);

	float topPipePos = rand()  % window->getSize().y;
	printf("a = %f\n", topPipePos);

	topPipeSprite.setPosition(window->getSize().x + topPipeSprite.getGlobalBounds().width, topPipePos);
	bottomPipeSprite.setPosition(window->getSize().x + topPipeSprite.getGlobalBounds().width, topPipePos + 250);

}

Pipe::Pipe(const Pipe& pipe) : Pipe{*(pipe.window)} 
{
	topPipeSprite.setPosition(pipe.topPipeSprite.getPosition().x, pipe.topPipeSprite.getPosition().y);
	bottomPipeSprite.setPosition(pipe.bottomPipeSprite.getPosition().x, pipe.bottomPipeSprite.getPosition().y);
}
