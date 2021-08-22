#pragma once
#include <SFML/Graphics.hpp>
#include <Definitions.h>

class State abstract
{
protected:
	sf::RenderWindow* window;
	sf::Texture windowBgImage;
	sf::Sprite windowBg;
public:
	State(sf::RenderWindow& _window);

	virtual void ProcessInput(sf::Event& inputEvent) = 0;
	virtual void Update() = 0;
	virtual void Draw();

};

