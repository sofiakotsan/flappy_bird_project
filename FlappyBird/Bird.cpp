#include "Bird.h"

Bird::Bird(sf::RenderWindow& _window) : window{ &_window}
{
	
	birdTexture.loadFromFile(BIRD_SPRITE_PATH);

	birdSprite.setTexture(birdTexture);

	birdSprite.setOrigin(0, birdSprite.getTextureRect().height / 2);

	birdSprite.setPosition(window->getSize().x / 9, window->getSize().y / 2);

	birdState = BirdState::Falling;

}

void Bird::Fly()
{
	flyingTime.restart();
	birdState = BirdState::Flying;
}