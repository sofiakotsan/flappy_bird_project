#include "Bird.h"

Bird::Bird(sf::RenderWindow& _window) : window{ &_window}
{
	
	birdTexture.loadFromFile(BIRD_SPRITE_PATH);

	birdSprite.setTexture(birdTexture);

	//birdSprite.setOrigin(birdSprite.getTextureRect().width / 2, birdSprite.getTextureRect().height / 2);
	birdSprite.setOrigin(0, birdSprite.getTextureRect().height / 2);

	birdSprite.setPosition(0, window->getSize().y / 2);

	birdState = BirdState::Falling;

}

void Bird::Fly()
{
	flyingTime.restart();
	birdState = BirdState::Flying;
}