#pragma once
#include <SFML/Graphics.hpp>

class State abstract
{
protected:
	sf::RenderWindow* window;
public:
	State(sf::RenderWindow& _window);

	virtual void ProcessInput(sf::Event& inputEvent) = 0;
	virtual void Update() = 0;
	virtual void Draw() = 0;

};

