#include "State.h"

State::State(sf::RenderWindow& _window, std::string windowBgImagePath) : window{ &_window } 
{
	windowBgImage.loadFromFile(windowBgImagePath);
	windowBg.setTexture(windowBgImage);
	windowBg.setPosition(0, 0);
}

void State::Draw() {
	window->clear();
	window->draw(windowBg);
}
