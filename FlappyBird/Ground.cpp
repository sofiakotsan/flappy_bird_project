#include "Ground.h"

Ground::Ground(sf::RenderWindow& _window) : window{ &_window }
{

	groundTexture.loadFromFile(GROUND_PATH);

	groundTexture.setRepeated(true);

	groundSprite.setTexture(groundTexture);

	groundSprite.setOrigin(0, groundSprite.getTextureRect().height);

	groundSprite.setPosition(0, window->getSize().y);
}