#pragma once
#include <SFML/Graphics.hpp>
#include <Definitions.h>
//#include <Game.h>

class State abstract
{
protected:
	sf::RenderWindow* window;
	sf::Texture windowBgImage;
	sf::Sprite windowBg;
	//std::shared_ptr<Game::GameState> currentStateEnum;
public:
	State(sf::RenderWindow& _window);

	virtual void ProcessInput(sf::Event& inputEvent) = 0;
	virtual void Update() = 0;
	virtual void Draw();

};

