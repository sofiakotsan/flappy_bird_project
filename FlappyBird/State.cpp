#include "State.h"

State::State(sf::RenderWindow& _window) : window{ &_window } 
{
	windowBgImage.loadFromFile(BACKGROUND_PATH);
	windowBg.setTexture(windowBgImage);
	windowBg.setPosition(0, 0);
}

void State::Draw() {
	window->clear();
	window->draw(windowBg);
}
