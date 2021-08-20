#include "Pipe.h"

Pipe::Pipe(sf::RenderWindow& _window) : window{ &_window }
{
	topPipeTexture.loadFromFile(TOP_PIPE_PATH);
	bottomPipeTexture.loadFromFile(BOTTOM_PIPE_PATH);

	topPipeSprite.setTexture(topPipeTexture);
	bottomPipeSprite.setTexture(bottomPipeTexture);

	topPipeSprite.setOrigin(topPipeSprite.getTextureRect().width / 2, 0);
	bottomPipeSprite.setOrigin(topPipeSprite.getTextureRect().width / 2, topPipeSprite.getTextureRect().height);
	//topPipeSprite.setOrigin(0, birdSprite.getTextureRect().height / 2);

	//birdSprite.setPosition(window->getSize().x / 9, window->getSize().y / 2);

	float topPipePos = rand() % window->getSize().y;
	printf("%f", topPipePos);

	topPipeSprite.setPosition(100, topPipePos);
	bottomPipeSprite.setPosition(100, topPipePos - 250);

}

Pipe::Pipe(const Pipe& pipe) : Pipe{*(pipe.window)} 
{
	topPipeSprite.setPosition(pipe.topPipeSprite.getPosition().x, pipe.topPipeSprite.getPosition().y);
	bottomPipeSprite.setPosition(pipe.bottomPipeSprite.getPosition().x, pipe.bottomPipeSprite.getPosition().y);
}
