#pragma once
#include <SFML/Graphics.hpp>

class State abstract
{
protected:
	sf::RenderWindow* window;
	sf::Texture windowBgImage;
	sf::Sprite windowBg;
public:
	State(sf::RenderWindow& _window, std::string windowBgImagePath);

	virtual void ProcessInput(sf::Event& inputEvent) = 0;
	virtual void Update(float deltaTime) = 0;
	virtual void Draw();

};

