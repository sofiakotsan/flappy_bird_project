#pragma once
#include <Definitions.h>
#include <State.h>
//#include <SFML/Graphics.hpp>
class GameOverState: public State
{
	sf::Texture gameOverLabelTexture;
	sf::Sprite gameOverLabel;

	sf::Texture scoreBoardTexture;
	sf::Sprite scoreBoard;

	sf::Texture playButtonTexture;
	sf::Sprite playButton;

	sf::Clock clock;
public:
	GameOverState(sf::RenderWindow& _window);
	void ProcessInput(sf::Event& inputEvent) override;
	void Update() override;
	void Draw() override;
};

