#include "Bird.h"

Bird::Bird()
{
	//sf::Texture()
	//birdTexture.se


	birdTexture.loadFromFile(BIRD_SPRITE_PATH);

	birdSprite.setTexture(birdTexture);

	birdSprite.setPosition(0, 0);


}