#pragma once
#include <SFML/Graphics.hpp>

class State abstract
{
public:
	virtual void ProcessInput(sf::Event& inputEvent) = 0;
	virtual void Update() = 0;
	virtual void Draw(sf::RenderWindow& window) = 0;

};

